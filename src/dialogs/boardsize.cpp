#include "boardsize.h"

BoardSize::BoardSize(QWidget *parent, Job * j) : QWidget(parent)
{
    job = j;
    dpi = this->job->dpi;
    main_layout = new QVBoxLayout(this);
    description = new QLabel(tr("Please select a board size:"));
    sizeopt1 = new QRadioButton(tr("4 Inches x 6 Inches"));
    sizeopt2 = new QRadioButton(tr("4 Inches x 6 Inches"));
    sizeopt3 = new QRadioButton(tr("9 Inches x 12 Inches"));
    sizecust = new QRadioButton(tr("custom size:"));
    main_layout->addWidget(description);
    main_layout->addWidget(sizeopt1);
    main_layout->addWidget(sizeopt2);
    main_layout->addWidget(sizeopt3);

    custom = new QHBoxLayout;
    height = new QLineEdit;
    width = new QLineEdit;
    heightu = new QLabel(tr("Inches x "));
    widthu = new QLabel(tr("Inches"));

    custom->addWidget(sizecust);
    custom->addWidget(height);
    custom->addWidget(heightu);
    custom->addWidget(width);
    custom->addWidget(widthu);

    main_layout->addLayout(custom);


}

 int BoardSize::toDPI(int m){return dpi* m;}
