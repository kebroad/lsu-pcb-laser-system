#ifndef DRILLSELECTION_H
#define DRILLSELECTION_H

#include <QObject>
#include <QDialog>
#include <QMessageBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QRadioButton>
#include <QButtonGroup>
#include <QCheckBox>
#include <QDialogButtonBox>
#include <QWidget>
#include <QLineEdit>
#include "general/job.h"
#include "boardlayout/boardselector.h"
#include <iostream>
#include <fstream>

class DrillSelector : public QWidget
{
    Q_OBJECT
public:
    explicit DrillSelector(QWidget *parent = nullptr, Job* j = new Job);

    bool board_added = 0;

    QVBoxLayout * main_layout;
    QVBoxLayout* add_remove;
    QVBoxLayout* button_layout;

    QLabel * logo;
    QLabel * description;
    QLabel * name;

    QHBoxLayout * speed_layout;
    QHBoxLayout * power_layout;

    QLabel * speed_label;
    QLabel * power_label;

    QLineEdit* speed;
    QLineEdit* power;

    QPushButton * add_board;
    QPushButton * remove_board;
    QPushButton * ok;

    QFile* tempf = new QFile;

    Job* job;

signals:

public slots:
    void set_drill()
    {
        power->setText("135");
        speed->setText("750");
    }

    void board_add()
    {
        QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
        QFile* file = new QFile;
        file->setFileName(fileName);
        QFileInfo fileInfo(file->fileName());
        QString filename(fileInfo.fileName());

        if (!file->exists())
        {
            QMessageBox::warning(this, "Warning", "Please select a file");
        }
        else if (!file->open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, "Warning", "Cannot open file: " + file->errorString());
        }
        else if(fileInfo.suffix() != "xln")
        {
            QMessageBox::warning(this, "Warning", "File must be a .xln file");
        }
        else
        {
            tempf = file;
        }
    }
    void board_remove()
    {
        if(board_added == false)
        {
            QMessageBox::warning(this, "Warning", "There is no board to remove");
        }
        else
        {
            QMessageBox::warning(this, "Warning", "Board removed");
            board_added = false;
        }
    }
};

#endif // DRILLSELECTION_H
