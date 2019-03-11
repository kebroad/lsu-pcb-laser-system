#ifndef STARTINGWIDGET_H
#define STARTINGWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "general/job.h"
#include <QStackedWidget>
#include "dialogs/boardsize.h"
#include "dialogs/boardtype.h"
#include "boardlayout/boardlayoutwidget.h"

class StartingWidget : public QDialog
{
    Q_OBJECT
public:
    QVBoxLayout main_layout;
    QHBoxLayout button_layout;
    explicit StartingWidget(QWidget *parent = nullptr, Job * j = new Job);
    Job* job;
    QStackedWidget* w;
    BoardSize* s;
    BoardType* t;
    BoardLayoutWidget* l;
    int current_index;

signals:

public slots:
    void accept(){
        if(this->t->top->isChecked()){
            job->job_type = TOP;
            this->close();
        }
        else if(this->t->top_sol->isChecked()){
            job->job_type = TOP_SOL;
            this->close();
        }
        else if(this->t->top_bot->isChecked()){
            job->job_type = TOP_BOT;
            this->close();
        }
        else if(this->t->top_bot_sol->isChecked()){
            job->job_type = TOP_BOT;
            this->close();
        }
        else{
            QMessageBox::warning(this, "Warning", "Please Select a board type before continuing");
        }
        if(this->s->sizeopt1->isChecked()){

        }
        else if(this->s->sizeopt2->isChecked()){

        }
        else if(this->s->sizeopt3->isChecked()){

        }
        else if(this->s->sizecust->isChecked()){
            job->height =  this->s->height->text().toInt();
            job->width =  this->s->width->text().toInt();
        }
        else{
            QMessageBox::warning(this, "Warning", "Please Select a size before continuing");
        }
        //if(s_ && t_)
    }
};

#endif // STARTINGWIDGET_H
