#include "job.h"

Job::Job(){
    board_amount = 1;
};


bool Job::isSame(Job j){
    if(this->job_type == j.job_type)
        return true;
    return false;
}

void Job::graphInit(){
   // assert(width !=0 && height != 0);
    border_width = border_width + 200;
    border_height = border_height + 200;
    origin.setX(border_width/2);
    origin.setY(border_height/2);
    border = new QRectF(origin.x(), origin.y(), width, height);
}



