#include "loadingwidget.h"

LoadingWidget::LoadingWidget(QWidget *parent) : QWidget(parent)
{
    main_layout = new QVBoxLayout(this);
    loading = new QLabel(tr("Routing in Progress. Please Wait"));
    main_layout->addWidget(loading);
}
