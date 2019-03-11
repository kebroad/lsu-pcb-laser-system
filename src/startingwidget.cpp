#include "startingwidget.h"

StartingWidget::StartingWidget(QWidget *parent, Job * j) : QDialog(parent)
{

    job = j;
    w = new QStackedWidget;
    current_index = 0;

    main_layout = new QVBoxLayout;
    button_layout = new QHBoxLayout;


    t = new BoardType;
    s = new BoardSize;
    l = new BoardLayoutWidget;

    w->setCurrentIndex(0);
    w->insertWidget(0, t);
    w->insertWidget(1, s);
    w->insertWidget(2,l);

}
