#ifndef RASTER_H
#define RASTER_H

#include <QFile>
#include <QImage>
#include <QTextStream>
#include "job.h"

enum Direction {UP, DOWN, LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT};

enum LaserMode {CONSTANT_LASER_POWER_MODE, DYNAMIC_LASER_POWER_MODE};

class Raster
{
public:
    LaserMode laser_mode;
    Job* job;
    double step_amt;
    int laser_intensity = 255;
    int speed = 750;

    Raster(Job* j, double stp, LaserMode l_mode, int lsr_intensity, int speed);

    QList<QString>  rasterRoute(QImage* image, int jt = 1);


    QList<QString>  isolateRoute(QImage * image);

    QImage* refineImage(QImage * image, int pixels);

    QHash<QPoint, bool> createLaserPoints(QImage* image);

    QPoint findClosest(QHash<QPoint, bool> list, QPoint original);

    Direction findLongestPathDir(QHash<QPoint, bool> list, QPoint point);

    QPoint nextPoint(QPoint point, Direction dir);



    int findXMIN(QImage * image);
    int findXMAX(QImage * image);
    int findYMIN(QImage * image);
    int findYMAX(QImage * image);

    bool isWhite(QRgb o);
    double step(int x);

};

#endif // RASTER_H
