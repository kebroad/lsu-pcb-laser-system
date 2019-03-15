#ifndef JOB_H
#define JOB_H

#include <QPointF>
#include <QFile>
#include <QGraphicsRectItem>

enum JobType {TOP, TOP_SOL, TOP_BOT, TOP_BOT_SOL };

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

    QRectF* border;
    double border_width = 0;
    double border_height = 0;
    QPointF origin;
    JobType job_type = TOP_BOT;
    int board_amount;
   
    QImage * top;
    QImage * bot;
    QImage * sol_top;
    QImage * sol_bot;

    QFile * top_gcode;
    QFile * bot_gcode;
    QFile * sol_top_gcode;
    QFile * sol_bot_gcode;

};

#endif // JOB_H
