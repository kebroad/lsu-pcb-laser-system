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
    QVBoxLayout* main_layout;
    QHBoxLayout* button_layout;
    explicit StartingWidget(QWidget *parent = nullptr, Job * j = new Job);
    Job* job;
    QStackedWidget* w;
    BoardSize* s;
    BoardType* t;
    BoardLayoutWidget* l;
    int current_index;

    QPushButton * next;
    QPushButton * previous;

signals:

public slots:
    void go_next(){
        switch (w->currentIndex()){
            case 0:
                job->speed = this->t->speed->text().toInt();
                job->power = this->t->power->text().toInt();
                job->invert = this->t->invert->isChecked();
                job->dpi = this->t->dpi->text().toInt();
                this->s = new BoardSize(NULL, this->job);
                w->insertWidget(1,s);
                if(this->t->top->isChecked()){
                    job->job_type = TOP;
                    w->setCurrentIndex(1);
                    previous->show();
                }
                else if(this->t->top_sol->isChecked()){
                    job->job_type = TOP_SOL;
                    w->setCurrentIndex(1);
                    previous->show();
                }
                else if(this->t->top_bot->isChecked()){
                    job->job_type = TOP_BOT;
                    w->setCurrentIndex(1);
                    previous->show();
                }
                else if(this->t->top_bot_sol->isChecked()){
                    job->job_type = TOP_BOT_SOL;
                    w->setCurrentIndex(1);
                    previous->show();
                }
                else if(this->t->mask->isChecked()){
                    job->job_type = TOP;
                    w->setCurrentIndex(1);
                    previous->show();
                }
                else{
                    QMessageBox::warning(this, "Warning", "Please Select a board type before continuing!");
                }
                break;
            case 1:
                if(this->s->sizeopt1->isChecked())
                {
                        w->setCurrentIndex(2);
                        this->job->graphInit();
                }
                else if(this->s->sizeopt2->isChecked())
                {
                        w->setCurrentIndex(2);
                        this->job->graphInit();
                }
                else if(this->s->sizecust->isChecked())
                {
                    job->height =  this->s->toDPI(this->s->height->text().toDouble());
                    job->width =  this->s->toDPI(this->s->width->text().toDouble());
                    this->job->graphInit();
                    this->l = new BoardLayoutWidget(NULL, this->job);

                    w->insertWidget(2,l);
                    w->setCurrentIndex(2);
                }
                else
                {
                    QMessageBox::warning(this, "Warning", "Please Select a board size before continuing!");
                }
                break;
            case 2:
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Warning", "Routing will start. Continue?",
                                            QMessageBox::Yes|QMessageBox::No);
                if (reply == QMessageBox::Yes) {
                    this->l->publishBoard();
                    accept();
                }
        }
    }
    void go_previous(){
        switch(this->w->currentIndex()){
        case 1:
            previous->hide();
            w->setCurrentIndex(0);
            break;
        case 2:
            w->setCurrentIndex(1);
           // w->removeWidget(l);
        }
    }
};

#endif // STARTINGWIDGET_H
