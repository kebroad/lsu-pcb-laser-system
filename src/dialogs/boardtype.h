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
#include <QLineEdit>
#include "general/job.h"

class BoardType : public QWidget
{
    Q_OBJECT
public:
    explicit BoardType(QWidget *parent = nullptr);
    QVBoxLayout * main_layout;
    QLabel * logo;
    QLabel * description;

    QHBoxLayout * speed_layout;
    QHBoxLayout * power_layout;
    QHBoxLayout * invert_layout;

    QLabel * speed_label;
    QLabel * power_label;
    QLabel * invert_label;
    QLineEdit* speed;
    QLineEdit* power;
    QRadioButton * invert;


    QRadioButton* mask;
    QRadioButton* top;
    QRadioButton* top_sol;
    QRadioButton* top_bot;
    QRadioButton* top_bot_sol;

signals:

public slots:
    void set_mask(bool checked){
        if(true){
            power->setText("900");
            speed->setText("600");
            invert->setChecked(false);
        }
    }
    void set_top(bool checked){
        if(true){
            power->setText("135");
            speed->setText("750");
            invert->setChecked(true);
        }
    }
    void set_top_sol(bool checked){
        if(true){
            power->setText("135");
            speed->setText("750");
            invert->setChecked(true);
        }
    }
    void set_top_bot(bool checked){
        if(true){
            power->setText("135");
            speed->setText("750");
            invert->setChecked(true);

        }
    }
    void set_top_bot_sol(bool checked){
        if(true){
            power->setText("135");
            speed->setText("750");
            invert->setChecked(true);
        }
    }
};

#endif // BOARDTYPE_H

