#include "raster.h"


Raster::Raster(Job* j, double stp, LaserMode l_mode, int laser_intensity, int speed)
{
    this->job = j;
    this->step_amt = stp;
    this->laser_mode = l_mode;
    this->laser_intensity = laser_intensity;

    this->speed = speed;

}

double Raster::step(int x){
    return this->step_amt * x;
}


bool Raster::isWhite(QRgb o){
    return (qRed(o) == 255) && (qBlue(o) == 255) && (qGreen(o) == 255);
}


int Raster::findXMIN(QImage * image){
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
    int max = 0;
    for(int i = 0; i < image->height(); i++){
        QRgb *line = (QRgb*) image->scanLine(i);
        for (int j = 0; j < image->width(); j++)
            if((!this->isWhite(line[j])) && i > max )
                max = i;
    }
    return max;
}


QList<QString> Raster::rasterRoute(QImage* image, int jt){
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


