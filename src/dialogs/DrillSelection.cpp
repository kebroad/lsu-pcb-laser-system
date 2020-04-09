#include "DrillSelection.h"

DrillSelector::DrillSelector(QWidget *parent, Job *j) : QWidget(parent)
{
     j= job;
     main_layout = new QVBoxLayout(this);
     button_layout = new QVBoxLayout;

     logo = new QLabel;
     description = new QLabel(tr("Please select an xln file:"));

     add_remove = new QVBoxLayout;
     button_layout->addLayout(add_remove);

     add_board = new QPushButton(tr("Add Board"));
     remove_board = new QPushButton("Remove Board");
     add_remove->addWidget(add_board);
     add_remove->addWidget(remove_board);

     QObject::connect(remove_board, SIGNAL(clicked()), this, SLOT(board_remove()));
     QObject::connect(add_board, SIGNAL(clicked()), this, SLOT(board_add()));

     speed_layout = new QHBoxLayout;
     power_layout = new QHBoxLayout;

     power = new QLineEdit;
     speed = new QLineEdit;

     speed_label = new QLabel(tr("Speed:"));
     power_label = new QLabel(tr("Power:"));

     speed_layout->addWidget(speed_label);
     speed_layout->addWidget(speed);

     power_layout->addWidget(power_label);
     power_layout->addWidget(power);

     set_drill();

     main_layout->addWidget(description);

     main_layout->addLayout(button_layout);
     main_layout->addLayout(speed_layout);
     main_layout->addLayout(power_layout);
}

