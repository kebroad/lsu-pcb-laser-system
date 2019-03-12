#include "boardtype.h"

BoardType::BoardType(QWidget *parent) : QWidget(parent)
{
     main_layout = new QVBoxLayout(this);
     logo = new QLabel;
     description = new QLabel(tr("Please select a board type:"));
     top = new QRadioButton("Top Side Only");
     top_sol = new QRadioButton("Top Side with Soldermask");
     top_bot = new QRadioButton("Top and Bottom Side");
     top_bot_sol = new QRadioButton("Top and Bottom Side with Soldermask");

     main_layout->addWidget(description);
     main_layout->addWidget(top);
     main_layout->addWidget(top_sol);
     main_layout->addWidget(top_bot);
     main_layout->addWidget(top_bot_sol);


}
