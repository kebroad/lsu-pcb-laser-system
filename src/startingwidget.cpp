#include "startingwidget.h"
#include <QApplication>
#include <QDesktopServices>
#include <QStyle>
#include <QDesktopWidget>
#include <QScreen>
#include <iostream>

StartingWidget::StartingWidget(QWidget *parent, Job * j) : QDialog(parent)
{
    Qt::WindowFlags flags = 0;

    flags |= Qt::WindowMinMaxButtonsHint;
    flags |= Qt::WindowCloseButtonHint;

    setWindowFlags( flags );

    std::cout << "About to change icon" << std::endl;
    setWindowIcon(QIcon(":/images/LSU_PCB_ICON.png"));
    job = j;
    w = new QStackedWidget;

    main_layout = new QVBoxLayout(this);
    button_layout = new QHBoxLayout;

    t = new BoardType;
    s = new BoardSize;

    w->setCurrentIndex(0);
    w->insertWidget(0, t);
    w->insertWidget(1, s);

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
