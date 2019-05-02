#include "boardselector.h"


BoardSelector1::BoardSelector1(int number, Job * job, QWidget *parent) : QWidget(parent)
{
    QString title = "board #";
    title.append(QString::number(number));
    QGroupBox * top = new QGroupBox(title, this);
    layout = new QVBoxLayout;
    board = new Board1(job->origin, job->invert);
    layer = new QLabel("Top Layer");
    name = new QLabel("No file selected");
    select = new QPushButton(tr("Upload"));
    connect(select, SIGNAL(clicked()), this, SLOT(setBoardTop()));


    layout->addWidget(layer);
    layout->addWidget(name);
    layout->addWidget(select);

    top->setLayout(layout);
}




BoardSelector2::BoardSelector2(int number, Job* job, QWidget *parent) : QWidget(parent)
{
    board = new Board2(job->origin, job->invert);

    QString title = "board #";
    title.append(QString::number(number));
    main = new QGroupBox(title, this);
    main_layout = new QHBoxLayout;


    top_box = new QGroupBox;
    top_box_layout = new QVBoxLayout;
    layer_top = new QLabel("Top Layer");
    name_top = new QLabel("No file selected");
    select_top = new QPushButton(tr("Upload"));
    connect(select_top, SIGNAL(clicked()), this, SLOT(setBoardTop()));
    top_box_layout->addWidget(layer_top);
    top_box_layout->addWidget(name_top);
    top_box_layout->addWidget(select_top);
    top_box->setLayout(top_box_layout);

    sol_top_box = new QGroupBox;
    sol_top_box_layout = new QVBoxLayout;
    layer_sol_top = new QLabel("Top Soldermask Layer");
    name_sol_top = new QLabel("No file selected");
    select_sol_top = new QPushButton(tr("Upload"));
    connect(select_sol_top, SIGNAL(clicked()), this, SLOT(setBoardSolTop()));
    sol_top_box_layout->addWidget(layer_sol_top);
    sol_top_box_layout->addWidget(name_sol_top);
    sol_top_box_layout->addWidget(select_sol_top);
    sol_top_box->setLayout(sol_top_box_layout);

    main_layout->addWidget(top_box);
    main_layout->addWidget(sol_top_box);

    main->setLayout(main_layout);
}



BoardSelector3::BoardSelector3(int number, Job * job, QWidget *parent) : QWidget (parent)
{
    board = new Board3(job->origin, job->invert);

    QString title = "board #";
    title.append(QString::number(number));
    main = new QGroupBox(title, this);
    main_layout = new QHBoxLayout;


    top_box = new QGroupBox;
    top_box_layout = new QVBoxLayout;
    layer_top = new QLabel("Top Layer");
    name_top = new QLabel("No file selected");
    select_top = new QPushButton(tr("Upload"));
    connect(select_top, SIGNAL(clicked()), this, SLOT(setBoardTop()));
    top_box_layout->addWidget(layer_top);
    top_box_layout->addWidget(name_top);
    top_box_layout->addWidget(select_top);
    top_box->setLayout(top_box_layout);

    bot_box = new QGroupBox;
    bot_box_layout = new QVBoxLayout;
    layer_bot = new QLabel("Bottom Layer");
    name_bot = new QLabel("No file selected");
    select_bot = new QPushButton(tr("Upload"));
    connect(select_bot, SIGNAL(clicked()), this, SLOT(setBoardBot()));
    bot_box_layout->addWidget(layer_bot);
    bot_box_layout->addWidget(name_bot);
    bot_box_layout->addWidget(select_bot);
    bot_box->setLayout(bot_box_layout);

    main_layout->addWidget(top_box);
    main_layout->addWidget(bot_box);

    main->setLayout(main_layout);
}

BoardSelector4::BoardSelector4(int number, Job * job, QWidget *parent) : QWidget (parent)
{
    board = new Board4(job->origin, job->invert);

    QString title = "board #";
    title.append(QString::number(number));
    main = new QGroupBox(title, this);
    main_layout = new QHBoxLayout;

    top_box = new QGroupBox;
    top_box_layout = new QVBoxLayout;
    layer_top = new QLabel("Top Layer");
    name_top = new QLabel("No file selected");
    select_top = new QPushButton(tr("Upload"));
    connect(select_top, SIGNAL(clicked()), this, SLOT(setBoardTop()));
    top_box_layout->addWidget(layer_top);
    top_box_layout->addWidget(name_top);
    top_box_layout->addWidget(select_top);
    top_box->setLayout(top_box_layout);

    bot_box = new QGroupBox;
    bot_box_layout = new QVBoxLayout;
    layer_bot = new QLabel("Bottom Layer");
    name_bot = new QLabel("No file selected");
    select_bot = new QPushButton(tr("Upload"));
    connect(select_bot, SIGNAL(clicked()), this, SLOT(setBoardBot()));
    bot_box_layout->addWidget(layer_bot);
    bot_box_layout->addWidget(name_bot);
    bot_box_layout->addWidget(select_bot);
    bot_box->setLayout(bot_box_layout);

    sol_top_box = new QGroupBox;
    sol_top_box_layout = new QVBoxLayout;
    layer_sol_top = new QLabel("Top Soldermask Layer");
    name_sol_top = new QLabel("No file selected");
    select_sol_top = new QPushButton(tr("Upload"));
    connect(select_sol_top, SIGNAL(clicked()), this, SLOT(setBoardSolTop()));
    sol_top_box_layout->addWidget(layer_sol_top);
    sol_top_box_layout->addWidget(name_sol_top);
    sol_top_box_layout->addWidget(select_sol_top);
    sol_top_box->setLayout(sol_top_box_layout);

    sol_bot_box = new QGroupBox;
    sol_bot_box_layout = new QVBoxLayout;
    layer_sol_bot = new QLabel("Bottom Soldermask Layer");
    name_sol_bot = new QLabel("No file selected");
    select_sol_bot = new QPushButton(tr("Upload"));
    connect(select_sol_bot, SIGNAL(clicked()), this, SLOT(setBoardSolBot()));
    sol_bot_box_layout->addWidget(layer_sol_bot);
    sol_bot_box_layout->addWidget(name_sol_bot);
    sol_bot_box_layout->addWidget(select_sol_bot);
    sol_bot_box->setLayout(sol_bot_box_layout);

    main_layout->addWidget(top_box);
    main_layout->addWidget(bot_box);
    main_layout->addWidget(sol_top_box);
    main_layout->addWidget(sol_bot_box);

    main->setLayout(main_layout);
}
