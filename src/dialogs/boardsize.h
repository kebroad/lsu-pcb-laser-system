#ifndef BOARDSIZE_H
#define BOARDSIZE_H

#include <QLineEdit>
#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QBoxLayout>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QLineEdit>

#include "general/job.h"

class BoardSize : public QDialog
{
    Q_OBJECT
public:
    explicit BoardSize(QWidget *parent = nullptr, Job * j = new Job);
    Job * job;
    QVBoxLayout * main_layout;
    QHBoxLayout * custom;
    QLabel * logo;
    QLabel * description;
    QRadioButton* sizeopt1;
    QRadioButton* sizeopt2;
    QRadioButton* sizeopt3;
    QRadioButton* sizecust;
    QLineEdit* height;
    QLineEdit* width;
signals:

public slots:
    void setopt(int opt){
        switch (opt){
        case 1:
            opt = 1;
            break;
        case 2:
            opt = 2;
            break;
        case 3:
            opt = 3;
            break;
        case 4:
            opt = 4;
            break;
        }
    }
};

#endif // BOARDSIZE_H
