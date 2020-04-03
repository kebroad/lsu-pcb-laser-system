#ifndef STARTINGWIDGET_H
#define STARTINGWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include "general/job.h"
#include <QStackedWidget>
#include "dialogs/boardsize.h"
#include "dialogs/boardtype.h"
#include "dialogs/DrillSelection.h"
#include "boardlayout/boardlayoutwidget.h"

class StartingWidget : public QDialog
{
    Q_OBJECT
public:
    QVBoxLayout* main_layout;
    QHBoxLayout* button_layout;
    QHBoxLayout* banner_layout;

    explicit StartingWidget(QWidget *parent = nullptr, Job * j = new Job);
    Job* job;
    QStackedWidget* w;
    QWidget* banner_w;
    BoardSize* s;
    BoardType* t;
    DrillSelector* d;
    BoardLayoutWidget* l;

    int current_index;

    QPushButton* banner;
    QPushButton* drill;
    QPushButton * laser;
    QPushButton * next;
    QPushButton * previous;

signals:

public slots:
    void selected_laser_job()
    {
        w->setCurrentIndex(0);
        laser->hide();
        drill->hide();
        banner->hide();
        previous->show();
        next->show();
        button_layout->addWidget(previous);
        button_layout->addWidget(next);
        w->insertWidget(0, t);
        w->insertWidget(1, s);
        connect(next, SIGNAL(clicked()), this, SLOT(laser_job()));
        connect(previous, SIGNAL(clicked()), this, SLOT(go_previous()));
    }

    void selected_drill_job()
    {
        w->setCurrentIndex(11);
        laser->hide();
        drill->hide();
        banner->hide();
        previous->show();
        next->show();
        button_layout->addWidget(previous);
        button_layout->addWidget(next);
        w->insertWidget(11, d);
        connect(next, SIGNAL(clicked()), this, SLOT(drill_job()));
        connect(previous, SIGNAL(clicked()), this, SLOT(go_previous()));
    }

    void laser_job()
    {
        switch (w->currentIndex())
        {
            case 0:
                job->speed = this->t->speed->text().toInt();
                job->power = this->t->power->text().toInt();
                job->invert = this->t->invert->isChecked();
                job->dpi = this->t->dpi->text().toInt();
                this->s = new BoardSize(NULL, this->job);
                w->insertWidget(1,s);
                if(this->t->top->isChecked())
                {
                    job->job_type = TOP;
                    w->setCurrentIndex(1);
                    previous->show();
                }
                else if(this->t->top_sol->isChecked())
                {
                    job->job_type = TOP_SOL;
                    w->setCurrentIndex(1);
                    previous->show();
                }
                else if(this->t->top_bot->isChecked())
                {
                    job->job_type = TOP_BOT;
                    w->setCurrentIndex(1);
                    previous->show();
                }
                else if(this->t->top_bot_sol->isChecked())
                {
                    job->job_type = TOP_BOT_SOL;
                    w->setCurrentIndex(1);
                    previous->show();
                }
                else if(this->t->mask->isChecked())
                {
                    job->job_type = TOP;
                    w->setCurrentIndex(1);
                    previous->show();
                }
                else
                {
                    QMessageBox::warning(this, "Warning", "Please Select a job type before continuing!");
                }
                break;
            case 1:
                this->move(200,200);
                if (this->s->sizeopt1->isChecked())
                {
                    job->height =  this->s->toDPI(4);
                    job->width =  this->s->toDPI(6);
                    this->job->graphInit();
                    this->l = new BoardLayoutWidget(NULL, this->job);

                    w->insertWidget(2,l);
                    w->setCurrentIndex(2);
                }
                else if (this->s->sizeopt2->isChecked())
                {
                    job->height =  this->s->toDPI(9);
                    job->width =  this->s->toDPI(12);
                    this->job->graphInit();
                    this->l = new BoardLayoutWidget(NULL, this->job);

                    w->insertWidget(2,l);
                    w->setCurrentIndex(2);
                }
                else if (this->s->sizecust->isChecked())
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
                reply = QMessageBox::question(this, "Warning", "Routing will start and the Candle app will now open. Continue?",
                                            QMessageBox::Yes|QMessageBox::No);
                if (reply == QMessageBox::Yes)
                {
                    this->l->publishBoard();
                    accept();
                }
        }
    }
    void drill_job()
    {
        switch (w->currentIndex())
        {
        case 11:
            job->speed = 750;
            job->power = 135;
            job->invert = true;
            job->job_type = DRILL;
            job->dpi = 500;
            job->height =  4;
            job->width =  6;
            this->job->graphInit();
            this->d = new DrillSelector(NULL);
            d->init(this->job);
            w->insertWidget(12,d);
            w->setCurrentIndex(12);
            previous->show();
            break;
        case 12:
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Warning", "Routing will start and the Candle app will now open. Continue?",
                                        QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes)
            {
                this->l->publishBoard();
                accept();
            }
        }
    }

    void go_previous()
    {
        switch (this->w->currentIndex())
        {
        case 0:
            w->removeWidget(t);
            w->removeWidget(s);
            previous->hide();
            next->hide();
            drill->show();
            laser->show();
            banner->show();
            w->setCurrentIndex(-1);
        case 1:
            w->setCurrentIndex(0);
            break;
        case 2:
            w->setCurrentIndex(1);
        case 11:
            w->removeWidget(d);
            previous->hide();
            next->hide();
            drill->show();
            laser->show();
            banner->show();
            w->setCurrentIndex(-1);
        case 12:
            w->setCurrentIndex(11);
        }
    }
};

#endif // STARTINGWIDGET_H
