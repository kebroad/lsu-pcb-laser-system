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

    setWindowIcon(QIcon(":/images/LSU_PCB_ICON.png"));
    job = j;
    w = new QStackedWidget;

    main_layout = new QVBoxLayout(this);
    button_layout = new QHBoxLayout;
    banner_layout = new QHBoxLayout;

    t = new BoardType;
    s = new BoardSize;

    main_layout->addWidget(w);
    button_layout->setSpacing(50);

    banner_layout->addWidget(banner_w);

    previous = new QPushButton(tr("Previous"));
    next = new QPushButton(tr("Next"));
    laser = new QPushButton();
    drill = new QPushButton();
    banner = new QPushButton();

    banner->setFixedSize(500,72);
    banner->setStyleSheet("background-image: url(:/images/lsu_banner.png)");

    laser->setFixedSize(225,225);
    laser->setStyleSheet("background-image: url(:/images/laser_button.png)");

    drill->setFixedSize(225,225);
    drill->setStyleSheet("background-image: url(:/images/drill_button.png)");

    w->setCurrentIndex(0);

    button_layout->addWidget(laser);
    button_layout->addWidget(drill);

    banner_layout->addWidget(banner);

    main_layout->addLayout(banner_layout);
    main_layout->addLayout(button_layout);

    connect(laser, SIGNAL(clicked()), this, SLOT(selected_laser_job()));
    connect(drill, SIGNAL(clicked()), this, SLOT(drill_job()));
}
