#ifndef BOARDTYPE_H
#define BOARDTYPE_H

#include <QObject>
#include <QDialog>
#include <QMessageBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QButtonGroup>
#include <QCheckBox>
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
    QHBoxLayout * non_invert_layout;
    QHBoxLayout * dpi_layout;

    QLabel * speed_label;
    QLabel * power_label;
    QLabel * invert_label;
    QLabel * non_invert_label;
    QLabel * dpi_label;

    QLineEdit* dpi;
    QLineEdit* speed;
    QLineEdit* power;

    QRadioButton * invert;
    QRadioButton * non_invert;

    QButtonGroup* groupOfCheckboxes;
    QCheckBox* mask;
    QCheckBox* top;
    QCheckBox* top_sol;
    QCheckBox* top_bot;
    QCheckBox* top_bot_sol;

signals:

public slots:
    void set_mask()
    {
        if(true)
        {
            power->setText("650");
            speed->setText("1000");
            non_invert->setChecked(true);
            dpi->setText("500");
        }
    }
    void set_top()
    {
        if(true)
        {
            power->setText("135");
            speed->setText("750");
            invert->setChecked(true);
            dpi->setText("500");
        }
    }
    void set_top_sol()
    {
        if(true)
        {
            power->setText("135");
            speed->setText("750");
            invert->setChecked(true);
            dpi->setText("500");
        }
    }
    void set_top_bot()
    {
        if(true)
        {
            power->setText("135");
            speed->setText("750");
            invert->setChecked(true);
            dpi->setText("500");
        }
    }
    void set_top_bot_sol()
    {
        if(true)
        {
            power->setText("135");
            speed->setText("750");
            invert->setChecked(true);
        }
    }
};

#endif // BOARDTYPE_H

