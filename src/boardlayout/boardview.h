#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QObject>
#include <QWidget>
#include <QTabWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "boardlayout/board.h"
#include "general/job.h"

class BoardView1 : public QWidget
{
    Q_OBJECT
public:
    explicit BoardView1(Job* j, QWidget *parent = nullptr);

    void addBoard(Board1* board);
    void removeBoard(Board1* board);
    QImage publishLayout();
    Job* job;
    QTabWidget * layers;
    QGraphicsView * top_view;
    QGraphicsScene * top_scene;
signals:

public slots:
};

class BoardView2 : public QWidget
{
    Q_OBJECT
public:
    Job* job;
    explicit BoardView2(Job * j, QWidget * parent = nullptr);
    void addBoard(Board2* board);
    void removeBoard(Board2* board);
    QImage publishLayoutTop();
    QImage publishLayoutSolTop();
    QTabWidget * layers;
    QGraphicsView * top_view;
    QGraphicsView * sol_top_view;
    QGraphicsScene * top_scene;
    QGraphicsScene * sol_top_scene;

signals:

public slots:

};


class BoardView3 : public QWidget
{
    Q_OBJECT
public:
    Job* job;
    explicit BoardView3(Job * j, QWidget * parent = nullptr);
    void addBoard(Board3* board);
    void removeBoard(Board3* board);
    QImage publishLayoutTop();
    QImage publishLayoutBot();
    QTabWidget * layers;
    QGraphicsView * top_view;
    QGraphicsView * bot_view;
    QGraphicsScene * top_scene;
    QGraphicsScene * bot_scene;

signals:

public slots:


};


class BoardView4 : public QWidget
{
    Q_OBJECT
public:
    Job* job;
    explicit BoardView4(Job* j, QWidget * parent = nullptr);
    void addBoard(Board4* board);
    void removeBoard(Board4* board);
    QImage publishLayoutTop();
    QImage publishLayoutBot();
    QImage publishLayoutSolTop();
    QImage publishLayoutSolBot();

    QTabWidget * layers;

    QGraphicsView * top_view;
    QGraphicsView * sol_top_view;
    QGraphicsView * bot_view;
    QGraphicsView * sol_bot_view;
    QGraphicsScene * top_scene;
    QGraphicsScene * sol_top_scene;
    QGraphicsScene * bot_scene;
    QGraphicsScene * sol_bot_scene;

signals:

public slots:


};

#endif // BOARDVIEW_H
