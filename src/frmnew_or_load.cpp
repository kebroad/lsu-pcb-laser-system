
#include "frmnew_or_load.h"
#include "ui_frmnew_or_load.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <iostream>
//#include "prejob.h"




frmNew_Or_Load::frmNew_Or_Load(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmNew_Or_Load)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(3);
    QPen pen(Qt::green, 3, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin);
    w->top_scene->addRect(0, 0, w->width, w->height, pen, Qt::NoBrush );



}



QString frmNew_Or_Load::upload_pixmap( int board, int layer){



    /*********************** old stuff
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
     QFile file(fileName);
     QFileInfo fileInfo(file.fileName());
     QString filename(fileInfo.fileName());
   //  currentFile = fileName;
     if (!file.open(QIODevice::ReadOnly)) {
         QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
         return NULL;
    }
    //setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    //ui->one_top_filename->setText(fileName);
    QPixmap pix;
    if(!pix.load(fileName)){
        qWarning("Failed to load");
    }
    switch (layer){
    case 1 :
        //w->top_pix[board].setOffset(0, 100);
       // w->bot_pix[board].setPixmap(pix);

        w->top_scene->addPixmap(pix);
      //  w->top_scene->
        QTransform transform;
        transform.translate(300,0);
        pix.transformed(transform, Qt::FastTransformation);

        //break;
   // case 2 :
        //w->bot_pix[board].setPixmap(pix);
        //break;
    //case 3:
        //w->stop_pix[board].setPixmap(pix);
      //  break;
    //case 4:
        //w->sbop_pix[board].setPixmap(pix);
        //break;
    }
    ********************************/



        QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
        QFile file(fileName);
         QFileInfo fileInfo(file.fileName());
         QString filename(fileInfo.fileName());
       //  currentFile = fileName;
         if (!file.open(QIODevice::ReadOnly)) {
             QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
             //return NULL;
        }
        //setWindowTitle(fileName);
        //QTextStream in(&file);
        //QString text = in.readAll();
        //ui->one_top_filename->setText(fileName);
        QPixmap pix;
        if(!pix.load(fileName)){
            qWarning("Failed to load");
       }

        //ui->View->addBoard(pix);
       ui->widget->addBoard(pix);


    return filename;
}

frmNew_Or_Load::~frmNew_Or_Load()
{
    delete ui;
}








void frmNew_Or_Load::on_new_job_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void frmNew_Or_Load::on_one_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}



void frmNew_Or_Load::on_board_1_top_upload_clicked()
{
    QString fileName = this->upload_pixmap(1, 1);
    ui->board_1_top_name->setText(fileName);

}

void frmNew_Or_Load::on_board_1_x_set_valueChanged(int arg1)
{
   // w->top_pix[1].setOffset(0, arg1);

}
