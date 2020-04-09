#ifndef JOB_H
#define JOB_H

#include <QPointF>
#include <QFile>
#include <QGraphicsRectItem>

enum JobType {TOP, TOP_SOL, TOP_BOT, TOP_BOT_SOL, DRILL };

class Job
{
public:
    explicit Job();
    bool isSame(Job j);
    void graphInit();
    int width = 0;
    int height = 0;
    int d_x = 200;
    int d_y = 200;

    int power;
    int speed;
    int dpi;
    bool invert;


    QRectF* border;
    double border_width = 0;
    double border_height = 0;
    QPoint origin;
    JobType job_type = TOP_BOT;
    int board_amount;
   
    QImage * top;
    QImage * bot;
    QImage * sol_top;
    QImage * sol_bot;
    QFile* drill;

    QFile * top_gcode;
    QFile * bot_gcode;
    QFile * sol_top_gcode;
    QFile * sol_bot_gcode;
    QFile* drill_gcode;

    QList<QString> top_gcode_data;
    QList<QString> bot_gcode_data;
    QList<QString> sol_top_gcode_data;
    QList<QString> sol_bot_gcode_data;
    QList<QString> drill_gcode_data;

};

#endif // JOB_H
