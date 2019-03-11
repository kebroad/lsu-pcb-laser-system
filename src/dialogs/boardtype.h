#ifndef BOARDTYPE_H
#define BOARDTYPE_H

#include <QObject>
#include <QDialog>
#include <QMessageBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QDialogButtonBox>
#include <QWidget>
#include "general/job.h"

class BoardType : public QDialog
{
    Q_OBJECT
public:
    explicit BoardType(QWidget *parent = nullptr, Job * j = new Job);
    Job* job;
    QVBoxLayout * main_layout;
    QLabel * logo;
    QLabel * description;

    QRadioButton* top;
    QRadioButton* top_sol;
    QRadioButton* top_bot;
    QRadioButton* top_bot_sol;

    QDialogButtonBox * buttonBox;
signals:

public slots:

};

#endif // BOARDTYPE_H

