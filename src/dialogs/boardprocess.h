#ifndef BOARDPROCESS_H
#define BOARDPROCESS_H

#include <QObject>
#include <QWidget>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "general/job.h"

class BoardProcess : public QWidget
{
    Q_OBJECT
public:
    explicit BoardProcess(QWidget *parent = nullptr, Job * j = new Job);
    Job * job;
       QVBoxLayout* main_layout;
       QLabel *  presets;
       QVBoxLayout * exposure_layout;
       QVBoxLayout * soldermask_layout;
       QVBoxLayout *



       QPushButton * start_job;
signals:

public slots:
};

#endif // BOARDPROCESS_H
