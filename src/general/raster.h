#ifndef RASTER_H
#define RASTER_H

#include <QFile>
#include <QImage>
#include <QTextStream>
#include "job.h"

enum LaserMode {CONSTANT_LASER_POWER_MODE, DYNAMIC_LASER_POWER_MODE};

class Raster
{
public:
    LaserMode laser_mode;
    Job* job;
    double step_amt;
    int laser_intensity = 255;

    Raster(Job* j, double stp, LaserMode l_mode, int lsr_intensity);

    QFile*  rasterRoute(QImage* image, int jt = 1);
    bool isWhite(QRgb o);
    double step(int x);

};

#endif // RASTER_H