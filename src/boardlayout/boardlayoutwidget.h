#ifndef BOARDLAYOUTWIDGET_H
#define BOARDLAYOUTWIDGET_H

#include <QObject>
#include <QDialog>
#include <QWidget>
#include <QBoxLayout>
#include <QVector>
#include "boardlayout/boardselector.h"
#include "general/job.h"
#include "boardlayout/boardview.h"





class BoardLayoutWidget : public QDialog
{
    Q_OBJECT
public:
    explicit BoardLayoutWidget(QWidget *parent = nullptr, Job* j = new Job());
    int board_amount = 0;
    QVector<BoardSelector1 *> board1;
    QVector<BoardSelector2 *> board2;
    QVector<BoardSelector3 *> board3;
    QVector<BoardSelector4 *> board4;

    BoardView1 * board_view1;
    BoardView2 * board_view2;
    BoardView3 * board_view3;
    BoardView4 * board_view4;

    QHBoxLayout* main_layout;
    QHBoxLayout* add_remove;

    QScrollArea* button_scroll;
    QWidget * generic_button_widget;
    QVBoxLayout* button_layout;

    QPushButton * add_board;
    QPushButton * remove_board;
    QPushButton * ok;
    Job* job;



public slots:
    void board_add(){
        job->board_amount++;
        switch (job->job_type) {
        case TOP:
            board1.append(new BoardSelector1(job->board_amount, job));
            button_layout->addWidget(board1.last());
            board1.last()->show();
            board_view1->addBoard(board1.last()->board);
            break;
        case TOP_SOL:
            board2.append(new BoardSelector2(job->board_amount, job));
            button_layout->addWidget(board2.last());
            board2.last()->show();
            board_view2->addBoard(board2.last()->board);
            break;
        case TOP_BOT:
            board3.append(new BoardSelector3(job->board_amount, job));
            button_layout->addWidget(board3.last());
            board3.last()->show();
            board_view3->addBoard(board3.last()->board);
            break;
        case TOP_BOT_SOL:
            board4.append(new BoardSelector4(job->board_amount, job));
            button_layout->addWidget(board4.last());
            board4.last()->show();
            board_view4->addBoard(board4.last()->board);
        }
    }
    void board_remove(){
        switch(job->job_type){
            case TOP:
                board_view1->removeBoard(board1.last()->board);
                button_layout->removeWidget(board1.last());
                board1.last()->hide();
                board1.removeLast();
                break;
            case TOP_SOL:
                board_view2->removeBoard(board2.last()->board);
                button_layout->removeWidget(board2.last());
                board2.last()->hide();
                board2.removeLast();
                break;
            case TOP_BOT:
                board_view3->removeBoard(board3.last()->board);
                button_layout->removeWidget(board3.last());
                board3.last()->hide();
                board3.removeLast();
                break;
            case TOP_BOT_SOL:
                board_view4->removeBoard(board4.last()->board);
                button_layout->removeWidget(board4.last());
                board4.last()->hide();
                board4.removeLast();
                break;
        }
        job->board_amount--;
    }
    void publishBoard(){
        switch(job->job_type){
            case TOP:
         {       job->top = new QImage(board_view1->publishLayout());
                break;
        }
            case TOP_SOL:
        {
                job->top = new QImage(board_view2->publishLayoutTop());
                QFile file1("top.png");
                file1.open(QIODevice::WriteOnly);
                job->top->save(&file1, "PNG");
                job->sol_top = new QImage(board_view2->publishLayoutSolTop());
                QFile file("sol_top.png");
                file.open(QIODevice::WriteOnly);
                job->sol_top->save(&file, "PNG");
                break;
        }
            case TOP_BOT:
        {
                job->top = new QImage(board_view3->publishLayoutTop());
                job->bot = new QImage(board_view3->publishLayoutBot());

                break;
        }
            case TOP_BOT_SOL:
            job->top = new QImage(board_view4->publishLayoutTop());
            QFile file1("top.png");
            file1.open(QIODevice::WriteOnly);
            job->top->save(&file1, "PNG");
            job->sol_top = new QImage(board_view4->publishLayoutSolTop());
            QFile file2("sol_top.png");
            file2.open(QIODevice::WriteOnly);
            job->sol_top->save(&file2, "PNG");
            job->bot = new QImage(board_view4->publishLayoutBot());
            QFile file3("bot.png");
            file3.open(QIODevice::WriteOnly);
            job->bot->save(&file3, "PNG");
            job->sol_bot = new QImage(board_view4->publishLayoutSolBot());

            QFile file4("sol_bot.png");
            file4.open(QIODevice::WriteOnly);
            job->sol_bot->save(&file4, "PNG");
                break;
        }
    }

signals:
    void sendJob(Job j);
};
#endif // BOARDLAYOUTWIDGET_H
