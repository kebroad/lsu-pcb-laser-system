#include "layerselection.h"

LayerSelection::LayerSelection(QWidget *parent, Job * j) : QWidget(parent)
{
    main_layout = new QHBoxLayout(this);
    top = new QPushButton("Top Layer");
    top_sol = new QPushButton("Top Soldermask Layer");
    bot = new QPushButton("Bottom Layer");
    bot_sol = new QPushButton("Bottom Soldermask Layer");
    drill = new QPushButton("Drill Job");

    main_layout->addWidget(top);

    switch (j->job_type)
    {
        case TOP:
            main_layout->addWidget(top);
        break;
        case TOP_SOL:
            main_layout->addWidget(top_sol);
        break;
        case TOP_BOT:
            main_layout->addWidget(bot);
        break;
        case TOP_BOT_SOL:
            main_layout->addWidget(top_sol);
            main_layout->addWidget(bot);
            main_layout->addWidget(bot_sol);
        break;
        case DRILL:
            main_layout->addWidget(drill);
        break;
    }
}
