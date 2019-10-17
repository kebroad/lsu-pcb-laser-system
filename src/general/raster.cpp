#include "raster.h"

#include <iostream>



Raster::Raster(Job* j, double stp, LaserMode l_mode, int laser_intensity, int speed)
{
    /*********************************************
    Info: Creates the raster object.
    Inputs:
    Job: the job throughout the program run
    stp: the smallest unit "step" transcribed from DPI (dots per inch). This is the real life length of ONE pixel on the input image
    l_mode: see https://github.com/gnea/grbl/wiki/Grbl-v1.1-Laser-Mode
    laser intensity: when the laser is on, the grbl "S" value of the laser
    speed: the speed the head moves at
    *********************************************/

    this->job = j;
    this->step_amt = stp;
    this->laser_mode = l_mode;
    this->laser_intensity = laser_intensity;
    this->speed = speed;

}

double Raster::step(int x){
    /*********************************************
    Info: Converts the number of pixels in the image (x) to the actual distance. by multiplying by Raster object's step_amt
    Inputs:
    x: number of pixels
    *********************************************/
    return this->step_amt * x;
}


bool Raster::isWhite(QRgb o){
    /*********************************************
    Info: Checks to see if the individual pixel is white (white = not exposed by laser).
          Ideally each input image should be a monochrome bitmap, but from what I've seen
          the Eagle CAM image addon will always make white the background even if monochrome isnt picked.
    Inputs:
    o: single pixel
    *********************************************/
    return (qRed(o) == 255) && (qBlue(o) == 255) && (qGreen(o) == 255);
}


int Raster::findXMIN(QImage * image){
    /*********************************************
    Info: finds the minimum lasered pixel from the bottom so it doesnt have to raster scan the whole plane of the QImage
    Inputs:
    image: image of the board plane
    *********************************************/
    int min = image->width()-1;
    for(int i = 0; i < image->height(); i++){
        QRgb *line = (QRgb*) image->scanLine(i);
        for (int j = 0; j < image->width(); j++)
            if((!this->isWhite(line[j])) && j < min )
                min = j;
    }
    return min;
}

int Raster::findXMAX(QImage * image){
    /*********************************************
    Info: finds the maximum lasered pixel from the top so it doesnt have to raster scan the whole plane of the QImage
    Inputs:
    image: image of the board plane
    *********************************************/
    int max = 0;
    for(int i = 0; i < image->height(); i++){
        QRgb *line = (QRgb*) image->scanLine(i);
        for (int j = 0; j < image->width(); j++)
            if((!this->isWhite(line[j])) && j > max )
                max = j;
    }
    return max;
}

int Raster::findYMIN(QImage * image){
    /*********************************************
    Info: finds the minimum lasered pixel from the bottom so it doesnt have to raster scan the whole plane of the QImage
    Inputs:
    image: image of the board plane
    *********************************************/
    int min = image->height() -1;
    for(int i = 0; i < image->height(); i++){
        QRgb *line = (QRgb*) image->scanLine(i);
        for (int j = 0; j < image->width(); j++)
            if((!this->isWhite(line[j])) && i < min )
                min = i;
    }
    return min;
}

int Raster::findYMAX(QImage * image){
    /*********************************************
    Info: finds the maximum lasered pixel from the top so it doesnt have to raster scan the whole plane of the QImage
    Inputs:
    image: image of the board plane
    *********************************************/
    int max = 0;
    for(int i = 0; i < image->height(); i++){
        QRgb *line = (QRgb*) image->scanLine(i);
        for (int j = 0; j < image->width(); j++)
            if((!this->isWhite(line[j])) && i > max )
                max = i;
    }
    return max;
}


QList<QString> Raster::rasterRoute(QImage *image, int jt)
{
    /*********************************************
    Info: The first and most primitive routing algorithm... literally goes from side to side scanning and turning on the laser for the areas that need it
    Inputs:
    image: image of the board plane
    Outputs:
    String List: list of individual lines of gcode
    *********************************************/
    *image = image->mirrored(false,true);
    int xmin = this->findXMIN(image);
    int xmax = this->findXMAX(image);
    int ymin = this->findYMIN(image);
    int ymax = this->findYMAX(image);
    QString temp;
    QTextStream  fstream(&temp);
    //image->invertPixels();

    bool laser_off_path = false;
    bool laser_on_path = false;
    fstream << "G90" << endl;
    fstream << "F" << this->speed << endl;
    fstream << "G0 X0 Y0 Z0" << endl;
    if(this->laser_mode == CONSTANT_LASER_POWER_MODE){
            fstream << "M3 S0" << endl;
    }
    else if (this->laser_mode == DYNAMIC_LASER_POWER_MODE){
            fstream << "M4 S0" << endl;
    }

    for(int i = ymin; i < ymax + 1; i++){
        int path_origin = 0;
        QRgb *line = (QRgb*) image->scanLine(i);
        if(i % 2 == 0){ //Odd line #'s, starting with 0, left to right
            for (int j = xmin ; j < xmax+1; j++) {
                if(isWhite(line[j]) && laser_off_path) continue;           //continue, nothing to see here
                else if(isWhite(line[j]) && laser_on_path){ // if currently on a laser on path
                        fstream << "G1 X" << step(j-1) << " S" << this->laser_intensity << endl;
                        laser_on_path = false; laser_off_path = true;
                }
                else if (isWhite(line[j]) && !laser_off_path && !laser_on_path){    // neither; start a laser on or a laser off path
                        laser_off_path = true; laser_on_path = false;
                }
                else if(!isWhite(line[j]) && laser_on_path) continue;
                else if(!isWhite(line[j]) && laser_off_path){    //if currently on a laser off path
                        fstream << "G0 X" << step(j-1) << " S0" << endl;
                        laser_off_path = false; laser_on_path = true;
                }
                else if(!isWhite(line[j]) && !laser_on_path && !laser_off_path){
                        laser_on_path = true; laser_off_path = false;
                }
            }
            if(laser_on_path){
                fstream << "G1 X" << step(image->width()-1) << " S" << this->laser_intensity << endl;
            }
            else if(laser_off_path){
                fstream << "G0 X" << step(image->width()-1) << " S0" << endl;
            }
            laser_on_path = false;
            laser_off_path = false;
            fstream << "G0 Y" << step(i+1) << " S0" << endl;

        }
        else{
            for(int j = xmax+1; j > xmin; j--){
                if(isWhite(line[j]) && laser_off_path) continue;           //continue, nothing to see here
                else if(isWhite(line[j]) && laser_on_path){ // if currently on a laser on path
                        fstream << "G1 X" << step(j+1) << " S" << this->laser_intensity << endl;
                        laser_on_path = false; laser_off_path = true;
                }
                else if (isWhite(line[j]) && !laser_off_path && !laser_on_path){    // neither; start a laser on or a laser off path
                        laser_off_path = true; laser_on_path = false;
                }
                else if(!isWhite(line[j]) && laser_on_path) continue;
                else if(!isWhite(line[j]) && laser_off_path){    //if currently on a laser off path
                        fstream << "G0 X" << step(j+1) << " S0" << endl;
                        laser_off_path = false; laser_on_path = true;
                }
                else if(!isWhite(line[j]) && !laser_on_path && !laser_off_path){
                        laser_on_path = true; laser_off_path = false;
                }
            }
            if(laser_on_path){
                fstream << "G1 X0 S" << this->laser_intensity << endl;
            }
            else if(laser_off_path){
                fstream << "G0 X0 S0" << endl;
            }
            laser_on_path = false;
            laser_off_path = false;
            fstream << "G0 Y" << step(i+1) << " S0" << endl;
        }
    }
    fstream << "M5" << endl;
    fstream << "G0 X0 Y0 Z0 S0" << endl;
    fstream.seek(0);
    QList<QString> data;
    while (!fstream.atEnd()) data.append(fstream.readLine());
    fstream.reset();

    return data;
}

QMap<QPoint, bool> list;

QPair <QList<QPoint>, QImage*> Raster::outboundEdges(QImage * image, int pixels){
    /*********************************************
    Info: takes away all lasered pixels bordering non-lasered pixels, and returns those pixels in a list along with the refined image
    Inputs:
    image: image of the board plane
    pixels: how many bordering pixels DEEP to take out
    Outputs:
    QPoint List: list of all the removed border-edge pixels removed
    QImage: the new refined image
    *********************************************/
    QList <QPoint> list;
    QImage * refined_image = new QImage(*image);

    for(int i = 0; i < image->height(); i++){
        for (int j = 0; j < image->width(); j++) {
            if(!this->isWhite(image->pixel(j,i))){
                int p = 1;
                //for(int p = 1; p < pixels; p++){
                    /*
                    if(this->isWhite(image->pixel(nextPoint(QPoint(j,i), UP)))
                    || this->isWhite(image->pixel(nextPoint(QPoint(j,i), DOWN)))
                    || this->isWhite(image->pixel(nextPoint(QPoint(j,i), LEFT)))
                    || this->isWhite(image->pixel(nextPoint(QPoint(j,i), RIGHT)))
                    || this->isWhite(image->pixel(nextPoint(QPoint(j,i), UP_LEFT)))
                    || this->isWhite(image->pixel(nextPoint(QPoint(j,i), UP_RIGHT)))
                    || this->isWhite(image->pixel(nextPoint(QPoint(j,i), DOWN_LEFT)))
                    || this->isWhite(image->pixel(nextPoint(QPoint(j,i), DOWN_RIGHT)))
                    */
                    if(this->isWhite(image->pixel(j+p,i))
                    || this->isWhite(image->pixel(j-p, i))
                    || this->isWhite(image->pixel(j, i+p))
                    || this->isWhite(image->pixel(j, i-p))
                    ){

                        list.append(QPoint(j,i));
                    }
                //}

            }
        }
    }
    for(int i = 0; i < list.size(); i++){
        refined_image->setPixelColor(list.at(i), QColor(255,255,255));
    }
    QPair <QList <QPoint>, QImage*> rvalue;
    rvalue.first =list;
    rvalue.second = refined_image;
    return rvalue;
}

QImage* Raster::refineImage(QImage * image, int pixels){
    /*********************************************
    Info: a primitive version of outbound edges. basically does the same thing with the image but doesnt return the lasered pixels removed
    Inputs:
    image: image of the board plane
    pixels: how many bordering pixels DEEP to take out
    Outputs:
    QPoint List: list of all the removed border-edge pixels removed
    QImage: the new refined image
    *********************************************/
    QImage * refined_image = new QImage(*image);
    for(int i = 0; i < image->height(); i++){
        for (int j = 0; j < image->width(); j++) {
            if(!this->isWhite(image->pixel(j,i))){
                for(int p = 1; p < pixels; p++){
                    if(this->isWhite(image->pixel(j+p,i))
                    || this->isWhite(image->pixel(j-p, i))
                    || this->isWhite(image->pixel(j, i+p))
                    || this->isWhite(image->pixel(j, i-p))
                    ){

                        refined_image->setPixelColor(j, i, QColor(255,255,255));
                    }
                }

            }

    }

    }
    return refined_image;
}

bool isWhite(QColor c){
        return (c == Qt::white);
}
inline uint qHash (const QPoint & key)
{
    return qHash (static_cast <qint64> (key.x () ) << 32 | key.y () );
}


bool variantLessThan(const QPoint &v1, const QPoint &v2)
{
    return v1.manhattanLength() < v2.manhattanLength();
}

QList <QPoint> Raster::createLaserPoints(QImage* image){
    QHash <QPoint, bool> yot;

    QList<QPoint> points;
    for(int i = 0; i < image->height(); i++){
        QRgb *line = (QRgb*) image->scanLine(i);
        for(int j = 0; j < image->width(); j++){
            if(!isWhite(line[j])){
                points.append(QPoint(j,i));
                yot.insert(QPoint(j,i), true);
                    if(yot.value(QPoint(j,i), false) == true)
                        yot.remove(QPoint(j,i));
            }
        }

    }

    return points;
}



QPoint Raster::findClosestBinary(QList <QPoint> list, QPoint original){
    /*********************************************
    Info: In a list of points, finds and returns the closest point from the original, using binary search (catch me on leetcode, yo)
    Inputs:
    list: list of points to find the closest one
    Original: the one we are trying to find the closest to
    Outputs:
    QPoint: the closes point to "original"
    *********************************************/
    if(list.size() == 1){
        return list.at(0);
    }
    else if(list.size() == 2){
        QPoint p0 = original - list.at(0);
        QPoint p1 = original - list.at(1);
        if(p0.manhattanLength() < p1.manhattanLength())
            return list.at(0);
        else{
            return list.at(1);
        }
    }
    else{
        int middle = list.size()/2+1;
        QPoint pa = findClosestBinary(list.mid(0, middle-1), original);
        QPoint pb = findClosestBinary(list.mid(middle, list.size()), original);
        QPoint pad = original - pa;
        QPoint pbd = original - pb;
        if(pad.manhattanLength() < pbd.manhattanLength())
            return pa;
        else{
            return pb;
        }
    }
}



QPoint Raster::findClosest(QList<QPoint> list, QPoint original){
    /*********************************************
    Info: In a list of points, finds and returns the closest point from the original, using O(n) :( . Obolete because of the binary one
    Inputs:
    list: list of points to find the closest one
    Original: the one we are trying to find the closest to
    Outputs:
    QPoint: the closes point to "original"
    *********************************************/
    if(list.isEmpty())
        return QPoint(-1,-1);
    for(int i = 0; i < 8; i++){ //check points around to make it faster
        QPoint p = nextPoint(original, (Direction)i);
        if(list.contains(p) == true)
                return p;
    }



    /*              old                 */

    QPoint rpoint = list.at(0);

    for (int i = 0 ; i < list.size(); i++) {
        QPoint pold = original - rpoint;
        QPoint pnew = original - list.at(i);
        if(pnew.manhattanLength() < pold.manhattanLength())
            rpoint = list.at(i);
    }


    //return findClosestBinary(list, original);

    return rpoint;

    /*              old                 */


}




QPair<Direction, int> Raster::findLongestPathDir(QList<QPoint> list, QPoint point){
    /*********************************************
    Info: Given a point and a list of other points, finds the longest path of points in any direction, and the length of that path
    Inputs:
    list: list of points to find longest path from "point"
    point: point where we are trying to find the longest path
    Outputs:
    QPoint: the closes point to "original"
    *********************************************/

    //for(Direction d = (Direction)0; d < directions; d =(Direction)(d+1))

    int counter = 0;
    Direction rdir = UP;
    for(int i = 0; i < 8; i++){
        int newcount = -1;
        QPoint p = point;
        do{
            newcount++;
            p = this->nextPoint(p, (Direction)i);
        }

        while(list.contains(p) != false);

        if(newcount > counter){
            rdir = (Direction)i;
            counter = newcount;
        }
    }
    QPair <Direction, int> rvalue;
    rvalue.first = rdir;
    rvalue.second = counter;
    return rvalue;
}



QPoint Raster::nextPoint(QPoint point, Direction dir){
    switch(dir){
    case UP:
        return QPoint(point.x(), point.y()+1);
        break;
    case DOWN:
        return QPoint(point.x(), point.y()-1);
        break;
    case LEFT:
        return QPoint(point.x()-1, point.y());
        break;
    case RIGHT:
        return QPoint(point.x()+1, point.y());
        break;
    case UP_LEFT:
        return QPoint(point.x()-1, point.y()+1);
        break;
    case UP_RIGHT:
        return QPoint(point.x()+1, point.y()+1);
        break;
    case DOWN_LEFT:
        return QPoint(point.x()-1, point.y()-1);
        break;
    case DOWN_RIGHT:
        return QPoint(point.x()+1, point.y()-1);
    }
}


QList<QString> Raster::isolateRoute(QImage* image){
    *image = image->mirrored(false,true);

    QString temp;
    QTextStream  fstream(&temp);

    QImage* refined_image = this->refineImage(image, 1);
    QList <QPoint> laser_points = this->createLaserPoints(refined_image);

    fstream << "G90" << endl;
    fstream << "F" << this->speed << endl;
    fstream << "G0 X0 Y0 Z0" << endl;
    if(this->laser_mode == CONSTANT_LASER_POWER_MODE){
            fstream << "M3 S0" << endl;
    }
    else if (this->laser_mode == DYNAMIC_LASER_POWER_MODE){
            fstream << "M4 S0" << endl;
    }

    QPoint previous_point = this->findClosest(laser_points, QPoint(0,0));
    Direction previous_dir;
    int previous_pathlen;

   do{
        fstream << "G0 X" <<  step(previous_point.x()) << " Y" << step(previous_point.y()) << "S0" << endl;

        QPair<Direction, int> tmp = this->findLongestPathDir(laser_points, previous_point);
        previous_dir = tmp.first;
        previous_pathlen = tmp.second;

        laser_points.removeOne(previous_point);
        QPoint final_point = previous_point;
        for(int i = 1; i < previous_pathlen; i++){
            final_point = this->nextPoint(final_point, previous_dir);
            laser_points.removeOne(final_point);
        }
        fstream << "G1 X" << step(final_point.x()) << " Y" << step(final_point.y()) << " S" << this->laser_intensity << endl;
        if(laser_points.empty())
            break;
        //previous_point = laser_points.at(0);
       previous_point =this->findClosest(laser_points, final_point);

    } while(!laser_points.empty());

    fstream << "M5" << endl;
    fstream << "G0 X0 Y0 Z0 S0" << endl;
    fstream.seek(0);
    QList<QString> data;
    while (!fstream.atEnd()) data.append(fstream.readLine());
    fstream.reset();

    return data;
}

QList<QString>  Raster::hybridRoute(QImage * image){
    /*********************************************
    Info: hybrid between rasterRoute and isolateRoute.
            Basically takes away bordering pixels for isolate route (clean edges), and then does the scanning thing for all interior pixels
    Inputs:
    image: image of the board plane
    Outputs:
    String List: list of individual lines of gcode
    *********************************************/
    *image = image->mirrored(false,true);

    QString temp;
    QTextStream  fstream(&temp);
    QPair <QList<QPoint>, QImage*> pair = this->outboundEdges(image, 2);



    QList <QPoint> laser_points = pair.first;

    fstream << "G90" << endl;
    fstream << "F" << this->speed << endl;
    fstream << "G0 X0 Y0 Z0" << endl;
    if(this->laser_mode == CONSTANT_LASER_POWER_MODE){
            fstream << "M3 S0" << endl;
    }
    else if (this->laser_mode == DYNAMIC_LASER_POWER_MODE){
            fstream << "M4 S0" << endl;
    }

    QPoint previous_point = this->findClosest(laser_points, QPoint(0,0));
    Direction previous_dir;
    int previous_pathlen;

   do{
        fstream << "G0 X" <<  step(previous_point.x()) << " Y" << step(previous_point.y()) << "S0" << endl;

        QPair<Direction, int> tmp = this->findLongestPathDir(laser_points, previous_point);
        previous_dir = tmp.first;
        previous_pathlen = tmp.second;

        laser_points.removeOne(previous_point);
        QPoint final_point = previous_point;
        for(int i = 1; i < previous_pathlen; i++){
            final_point = this->nextPoint(final_point, previous_dir);
            laser_points.removeOne(final_point);
        }
        fstream << "G1 X" << step(final_point.x()) << " Y" << step(final_point.y()) << " S" << this->laser_intensity << endl;
        if(laser_points.empty())
            break;
        //previous_point = laser_points.at(0);
       previous_point =this->findClosest(laser_points, final_point);

    } while(!laser_points.empty());

    fstream << "M5" << endl;
    fstream << "G0 X0 Y0 Z0 S0" << endl;
    fstream.seek(0);
    QList<QString> data;
    while (!fstream.atEnd()) data.append(fstream.readLine());
    fstream.reset();


    *pair.second = pair.second->mirrored(false,true);
    data.append(rasterRoute(pair.second));

    return data;
}
