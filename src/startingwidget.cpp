#include "startingwidget.h"

StartingWidget::StartingWidget(QWidget *parent, Job * j) : QDialog(parent)
{
    setWindowIcon(QIcon(":/images/LSU_PCB_ICON.png"));
    showMaximized();
    job = j;
    w = new QStackedWidget;

    main_layout = new QVBoxLayout(this);
    button_layout = new QHBoxLayout;




    t = new BoardType;
    s = new BoardSize;


    w->setCurrentIndex(0);
    w->insertWidget(0, t);
    w->insertWidget(1, s);
   // w->insertWidget(2,l);

    main_layout->addWidget(w);


    previous = new QPushButton(tr("Previous"));
    next = new QPushButton(tr("Next"));


        previous->hide();





    button_layout->addWidget(previous);

    button_layout->addWidget(next);
    main_layout->addLayout(button_layout);


    connect(next, SIGNAL(clicked()), this, SLOT(go_next()));
    connect(previous, SIGNAL(clicked()), this, SLOT(go_previous()));

}
