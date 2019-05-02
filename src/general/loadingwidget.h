#ifndef LOADINGWIDGET_H
#define LOADINGWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class LoadingWidget: public QWidget
{
    Q_OBJECT

public:
    explicit LoadingWidget(QWidget *parent = nullptr);
    QVBoxLayout* main_layout;
    QLabel* loading;
};

#endif // LOADINGWIDGET_H
