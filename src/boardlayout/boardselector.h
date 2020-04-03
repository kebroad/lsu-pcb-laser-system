#ifndef BOARDSELECTOR_H
#define BOARDSELECTOR_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>

#include "general/job.h"
#include "board.h"

class BoardSelector1 : public QWidget
{
    Q_OBJECT
public:
    Board1 * board;
    explicit BoardSelector1( int number = 0 ,Job* job = new Job, QWidget *parent = nullptr);
    QVBoxLayout * layout;
    QGroupBox * top_box;
    QLabel * layer;
    QLabel * name;
    QPushButton* select;


signals:

public slots:
    void setBoardTop()
    {
        QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
        QFile file(fileName);
         QFileInfo fileInfo(file.fileName());
         QString filename(fileInfo.fileName());
         if (!file.open(QIODevice::ReadOnly)) {
             QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        }
         QPixmap pix;
         if(!pix.load(fileName)){
             qWarning("Failed to load");
        }
        board->setBoardTop(pix);
        name->setText(filename);
    }
};

class BoardSelector2 : public QWidget
{
    Q_OBJECT
public:
    Board2 * board;
    explicit BoardSelector2(int number = 1, Job * job = new Job, QWidget *parent = nullptr);
    //~BoardSelector2();
    QGroupBox* main;
    QHBoxLayout * main_layout;

    QGroupBox * top_box;
    QGroupBox * sol_top_box;

    QVBoxLayout *top_box_layout;
    QVBoxLayout *sol_top_box_layout;

    QLabel * layer_top;
    QLabel * name_top;
    QPushButton* select_top;

    QLabel * layer_sol_top;
    QLabel * name_sol_top;
    QPushButton* select_sol_top;
signals:

public slots:
    void setBoardTop(){
            QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
            QFile file(fileName);
             QFileInfo fileInfo(file.fileName());
             QString filename(fileInfo.fileName());
             if (!file.open(QIODevice::ReadOnly)) {
                 QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
            }
             QPixmap pix;
             if(!pix.load(fileName)){
                 qWarning("Failed to load");
            }
            board->setBoardTop(pix);
            name_top->setText(filename);
    }
    void setBoardSolTop(){
        QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
        QFile file(fileName);
         QFileInfo fileInfo(file.fileName());
         QString filename(fileInfo.fileName());
         if (!file.open(QIODevice::ReadOnly)) {
             QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        }
         QPixmap pix;
         if(!pix.load(fileName)){
             qWarning("Failed to load");
        }
        board->setBoardSolTop(pix);
        name_sol_top->setText(filename);

    }
};

class BoardSelector3 : public QWidget
{
    Q_OBJECT
public:
    Board3 * board;
    explicit BoardSelector3(int number = 1,  Job * job = new Job, QWidget *parent = nullptr);
    //~BoardSelector3();
    QGroupBox* main;
    QHBoxLayout * main_layout;

    QGroupBox * top_box;
    QGroupBox * bot_box;

    QVBoxLayout *top_box_layout;
    QVBoxLayout *bot_box_layout;

    QLabel * layer_top;
    QLabel * name_top;
    QPushButton* select_top;

    QLabel * layer_bot;
    QLabel * name_bot;
    QPushButton* select_bot;

signals:

public slots:
    void setBoardTop(){
        QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
        QFile file(fileName);
         QFileInfo fileInfo(file.fileName());
         QString filename(fileInfo.fileName());
         if (!file.open(QIODevice::ReadOnly)) {
             QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        }
         QPixmap pix;
         if(!pix.load(fileName)){
             qWarning("Failed to load");
        }
        board->setBoardTop(pix);
        name_top->setText(filename);
    }
    void setBoardBot(){
        QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
        QFile file(fileName);
         QFileInfo fileInfo(file.fileName());
         QString filename(fileInfo.fileName());
         if (!file.open(QIODevice::ReadOnly)) {
             QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        }
         QPixmap pix;
         if(!pix.load(fileName)){
             qWarning("Failed to load");
        }
        board->setBoardBot(pix);
        name_bot->setText(filename);
    }
};

class BoardSelector4 : public QWidget
{
    Q_OBJECT
public:
    Board4 * board;
    explicit BoardSelector4(int number = 1, Job * job = new Job, QWidget *parent = nullptr);
    //~BoardSelector4();

    QGroupBox * main;
    QHBoxLayout * main_layout;

    QGroupBox * top_box;
    QGroupBox * bot_box;
    QGroupBox * sol_top_box;
    QGroupBox * sol_bot_box;

    QVBoxLayout * top_box_layout;
    QVBoxLayout * bot_box_layout;
    QVBoxLayout * sol_top_box_layout;
    QVBoxLayout * sol_bot_box_layout;

    QLabel * layer_top;
    QLabel * name_top;
    QPushButton* select_top;

    QLabel * layer_bot;
    QLabel * name_bot;
    QPushButton* select_bot;

    QLabel * layer_sol_top;
    QLabel * name_sol_top;
    QPushButton* select_sol_top;

    QLabel * layer_sol_bot;
    QLabel * name_sol_bot;
    QPushButton* select_sol_bot;
signals:

public slots:
    void setBoardTop(){
         QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
         QFile file(fileName);
          QFileInfo fileInfo(file.fileName());
          QString filename(fileInfo.fileName());
          if (!file.open(QIODevice::ReadOnly)) {
              QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
         }
          QPixmap pix;
          if(!pix.load(fileName)){
              qWarning("Failed to load");
         }
         board->setBoardTop(pix);
         name_top->setText(filename);
    }
    void setBoardBot(){
        QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
        QFile file(fileName);
         QFileInfo fileInfo(file.fileName());
         QString filename(fileInfo.fileName());
         if (!file.open(QIODevice::ReadOnly)) {
             QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        }
         QPixmap pix;
         if(!pix.load(fileName)){
             qWarning("Failed to load");
        }
        board->setBoardBot(pix);
        name_bot->setText(filename);
    }
    void setBoardSolTop(){
        QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
        QFile file(fileName);
         QFileInfo fileInfo(file.fileName());
         QString filename(fileInfo.fileName());
         if (!file.open(QIODevice::ReadOnly)) {
             QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        }
         QPixmap pix;
         if(!pix.load(fileName)){
             qWarning("Failed to load");
        }
        board->setBoardSolTop(pix);
        name_sol_top->setText(filename);
    }
    void setBoardSolBot(){
        QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
        QFile file(fileName);
         QFileInfo fileInfo(file.fileName());
         QString filename(fileInfo.fileName());
         if (!file.open(QIODevice::ReadOnly)) {
             QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        }
         QPixmap pix;
         if(!pix.load(fileName)){
             qWarning("Failed to load");
        }
        board->setBoardSolBot(pix);
        name_sol_bot->setText(filename);
    }
};

#endif // BOARDSELECTOR_H
