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
#include <QDialogButtonBox>
#include <QMessageBox>

#include "general/job.h"

class BoardSize : public QDialog
{
    Q_OBJECT
public:
    explicit BoardSize(QWidget *parent = nullptr, Job * j = new Job);
    int option;
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
    QLabel * heightu;
    QLabel * widthu;

    QDialogButtonBox * buttonBox;
signals:

public slots:
    void setopt(int opt){
        switch (opt){
        case 1:
            option = 1;
            break;
        case 2:
            option = 2;
            break;
        case 3:
            option = 3;
            break;
        case 4:
            option = 4;
            break;
        }
    }
    void accept(){
        if(this->sizeopt1->isChecked()){

        }
        else if(this->sizeopt2->isChecked()){

        }
        else if(this->sizeopt3->isChecked()){

        }
        else if(this->sizecust->isChecked()){
            job->height =  this->height->text().toInt();
            job->width =  this->width->text().toInt();
            this->close();
        }
        else{
            QMessageBox::warning(this, "Warning", "Please Select a size before continuing");
        }
    }
};

#endif // BOARDSIZE_H
