#ifndef LAYERSELECTION_H
#define LAYERSELECTION_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include "general/job.h"

class LayerSelection : public QWidget
{
    Q_OBJECT
public:
    explicit LayerSelection(QWidget *parent = nullptr, Job * j = new Job);

    QHBoxLayout * main_layout;
    QPushButton * top;
    QPushButton * top_sol;
    QPushButton * bot;
    QPushButton * bot_sol;

signals:

public slots:
};

#endif // LAYERSELECTION_H
