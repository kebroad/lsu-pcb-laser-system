#ifndef RASTER_H
#define RASTER_H

#include <QFile>
#include <QImage>
#include <QTextStream>
#include <iostream>
#include <fstream>
#include "job.h"

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    UP_LEFT,
    UP_RIGHT,
    DOWN_LEFT,
    DOWN_RIGHT
};

enum LaserMode
{
    CONSTANT_LASER_POWER_MODE,
    DYNAMIC_LASER_POWER_MODE
};

class Raster
{
public:
    LaserMode laser_mode;
    Job* job;
    double step_amt;
    int laser_intensity = 255;
    int speed = 750;

    Raster(Job* j, double stp, LaserMode l_mode, int lsr_intensity, int speed);

    bool Drill(Job* j, std::ifstream* f);
  
    QList<QString>  rasterRoute(QImage* image);

    QList<QString>  isolateRoute(QImage * image);

    QList<QString>  hybridRoute(QImage * image);

    QList<QString> drill(QFile* f);

    QImage* refineImage(QImage * image, int pixels);

    QList<QPoint> createLaserPoints(QImage* image);

    QPoint findClosest(QList<QPoint> list, QPoint original);

    QPoint findClosestBinary(QList <QPoint> list, QPoint original);

    QPair<Direction, int> findLongestPathDir(QList<QPoint> list, QPoint point);

    QPoint nextPoint(QPoint point, Direction dir);

    QPair <QList<QPoint>, QImage*> outboundEdges(QImage * image);

    int findXMIN(QImage * image);
    int findXMAX(QImage * image);
    int findYMIN(QImage * image);
    int findYMAX(QImage * image);

    bool isWhite(QRgb o);
    double step(int x);

};

#endif // RASTER_H
