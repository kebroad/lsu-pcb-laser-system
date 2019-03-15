#include "boardlayoutwidget.h"


BoardLayoutWidget::BoardLayoutWidget(QWidget *parent, Job * j) : QDialog(parent)
{

  //  showMaximized();
   // setWindowState(Qt::WindowMaximized);
    job = j;


    main_layout = new QHBoxLayout(this);
    button_layout = new QVBoxLayout;

    add_remove = new QHBoxLayout;
    button_layout->addLayout(add_remove);


    add_board = new QPushButton("Add Board");
    remove_board = new QPushButton("Remove Board");
    add_remove->addWidget(add_board);
    add_remove->addWidget(remove_board);

    QObject::connect(remove_board, SIGNAL(clicked()), this, SLOT(board_remove()));
    QObject::connect(add_board, SIGNAL(clicked()), this, SLOT(board_add()));


    switch (job->job_type){

        case TOP:
            board_view1 = new BoardView1(job);
            main_layout->addWidget(board_view1);
            board1.append(new BoardSelector1(1));
            button_layout->addWidget(board1.at(0));
            board1.at(0)->show();
            board_view1->addBoard(board1.at(0)->board);
            setMinimumSize(board_view1->top_view->width() + 500, board_view1->top_view->height() + 100);
            break;
        case TOP_SOL:
            board_view2 = new BoardView2(job);
            main_layout->addWidget(board_view2);
            board2.append(new BoardSelector2(1));
            button_layout->addWidget(board2.at(0));
            board2.at(0)->show();
            board_view2->addBoard(board2.at(0)->board);
            break;
        case TOP_BOT:
            board_view3 = new BoardView3(job);
            main_layout->addWidget(board_view3);
            board3.append(new BoardSelector3);
            button_layout->addWidget(board3.at(0));
            board3.at(0)->show();
            board_view3->addBoard(board3.at(0)->board);
            break;
        case TOP_BOT_SOL:
            board_view4 = new BoardView4(job);
            main_layout->addWidget(board_view4);
            board4.append(new BoardSelector4(1));
            button_layout->addWidget(board4.at(0));
            board4.at(0)->show();
            board_view4->addBoard(board4.at(0)->board);
            break;
    }
    main_layout->addLayout(button_layout);







}


