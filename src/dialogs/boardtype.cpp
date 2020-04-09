#include "boardtype.h"

BoardType::BoardType(QWidget *parent) : QWidget(parent)
{
     invert = new QRadioButton;
     non_invert = new QRadioButton;
     main_layout = new QVBoxLayout(this);
     logo = new QLabel;
     description = new QLabel(tr("Please select a job type:"));
     invert->setAutoExclusive(true);
     non_invert->setAutoExclusive(true);

     groupOfCheckboxes = new QButtonGroup;

     mask = new QCheckBox("Photolith Mask");
     top = new QCheckBox("Top Side Only");
     top_sol = new QCheckBox("Top Side with Soldermask");
     top_bot = new QCheckBox("Top and Bottom Side");
     top_bot_sol = new QCheckBox("Top and Bottom Side with Soldermask");

     groupOfCheckboxes->addButton(mask);
     groupOfCheckboxes->addButton(top);
     groupOfCheckboxes->addButton(top_sol);
     groupOfCheckboxes->addButton(top_bot);
     groupOfCheckboxes->addButton(top_bot_sol);

     speed_layout = new QHBoxLayout;
     power_layout = new QHBoxLayout;
     invert_layout = new QHBoxLayout;
     dpi_layout = new QHBoxLayout;

     power = new QLineEdit;
     speed = new QLineEdit;
     dpi = new QLineEdit;


     speed_label = new QLabel(tr("Speed:"));
     power_label = new QLabel(tr("Power:"));
     invert_label = new QLabel(tr("Negative Photoresist:"));
     non_invert_label = new QLabel(tr("Positive Photoresist:"));
     dpi_label = new QLabel(tr("DPI:"));

     speed_layout->addWidget(speed_label);
     speed_layout->addWidget(speed);

     power_layout->addWidget(power_label);
     power_layout->addWidget(power);

     invert_layout->addWidget(invert_label);
     invert_layout->addWidget(invert);
     invert_layout->addWidget(non_invert_label);
     invert_layout->addWidget(non_invert);

     dpi_layout->addWidget(dpi_label);
     dpi_layout->addWidget(dpi);

     QObject::connect(mask, SIGNAL(toggled(bool)), this, SLOT(set_mask()));
     QObject::connect(top, SIGNAL(toggled(bool)), this, SLOT(set_top()));
     QObject::connect(top_sol, SIGNAL(toggled(bool)), this, SLOT(set_top_sol()));
     QObject::connect(top_bot, SIGNAL(toggled(bool)), this, SLOT(set_top_bot()));
     QObject::connect(top_bot_sol, SIGNAL(toggled(bool)), this, SLOT(set_top_bot_sol()));

     main_layout->addWidget(description);
     main_layout->addWidget(mask);
     main_layout->addWidget(top);
     main_layout->addWidget(top_sol);
     main_layout->addWidget(top_bot);
     main_layout->addWidget(top_bot_sol);

     main_layout->addLayout(speed_layout);
     main_layout->addLayout(power_layout);
     main_layout->addLayout(invert_layout);
     main_layout->addLayout(dpi_layout);
}
