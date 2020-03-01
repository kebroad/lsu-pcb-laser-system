#include "job.h"

Job::Job()
{
    board_amount = 1;
};


bool Job::isSame(Job j)
{
    if (this->job_type == j.job_type)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Job::graphInit()
{
    border_width = width + d_x;
    border_height = height + d_y;
    origin.setX(width/2);
    origin.setY(height/2);
    border = new QRectF(origin.x()+(d_x/2), origin.y()+(d_y/2), width, height);
}




