#ifndef FRMNEW_OR_LOAD_H
#define FRMNEW_OR_LOAD_H

#include <QDialog>

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include "view.h"
#include "prejob.h"

namespace Ui {
class frmNew_Or_Load;
}

class frmNew_Or_Load : public QDialog
{
    Q_OBJECT

public:
    explicit frmNew_Or_Load(QWidget *parent = nullptr);
    ~frmNew_Or_Load();
       PreJob* w = new PreJob;
       QString upload_pixmap(int board, int layer);
private slots:


    void on_new_job_clicked();

    void on_one_clicked();




    void on_board_1_top_upload_clicked();


    void on_board_1_x_set_valueChanged(int arg1);

private:
    Ui::frmNew_Or_Load *ui;
};

#endif // FRMNEW_OR_LOAD_H
