#include "boardtype.h"

BoardType::BoardType(QWidget *parent) : QWidget(parent)
{
    invert = new QRadioButton;
    non_invert = new QRadioButton;
    invert->setAutoExclusive(true);
    non_invert->setAutoExclusive(true);
     main_layout = new QVBoxLayout(this);
     logo = new QLabel;
     description = new QLabel(tr("Please select a board type:"));
     mask = new QRadioButton("Photolith Mask");
     top = new QRadioButton("Top Side Only");
     top_sol = new QRadioButton("Top Side with Soldermask");
     top_bot = new QRadioButton("Top and Bottom Side");
     top_bot_sol = new QRadioButton("Top and Bottom Side with Soldermask");

     speed_layout = new QHBoxLayout;
     power_layout = new QHBoxLayout;
     invert_layout = new QHBoxLayout;
     non_invert_layout = new QHBoxLayout;
     dpi_layout = new QHBoxLayout;

     power = new QLineEdit;
     speed = new QLineEdit;
     dpi = new QLineEdit;


     speed_label = new QLabel(tr("Speed:"));
     power_label = new QLabel(tr("Power:"));
     invert_label = new QLabel(tr("Invert:"));
     non_invert_label = new QLabel(tr("Don't Invert:"));
     dpi_label = new QLabel(tr("DPI:"));

     speed_layout->addWidget(speed_label);
     speed_layout->addWidget(speed);

     power_layout->addWidget(power_label);
     power_layout->addWidget(power);

     invert_layout->addWidget(invert_label);
     invert_layout->addWidget(invert);

     non_invert_layout->addWidget(non_invert_label);
     non_invert_layout->addWidget(non_invert);

     dpi_layout->addWidget(dpi_label);
     dpi_layout->addWidget(dpi);

     QObject::connect(mask, SIGNAL(toggled(bool)), this, SLOT(set_mask(bool)));
     QObject::connect(top, SIGNAL(toggled(bool)), this, SLOT(set_top(bool)));
     QObject::connect(top_sol, SIGNAL(toggled(bool)), this, SLOT(set_top_sol(bool)));
     QObject::connect(top_bot, SIGNAL(toggled(bool)), this, SLOT(set_top_bot(bool)));
     QObject::connect(top_bot_sol, SIGNAL(toggled(bool)), this, SLOT(set_top_bot_sol(bool)));

     main_layout->addWidget(description);
     main_layout->addWidget(mask);
     main_layout->addWidget(top);
     main_layout->addWidget(top_sol);
     main_layout->addWidget(top_bot);
     main_layout->addWidget(top_bot_sol);

     main_layout->addLayout(speed_layout);
     main_layout->addLayout(power_layout);
     main_layout->addLayout(invert_layout);
     main_layout->addLayout(non_invert_layout);
     main_layout->addLayout(dpi_layout);
}
