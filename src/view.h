#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsView>

#include <notifier.h>

/********** ORIGINAL *************
class View
{
public:
    View();
};
********************************/


class View : public QGraphicsView
{
   Q_OBJECT
   QGraphicsScene scene;
   QGraphicsSimpleTextItem text;
   QGraphicsRectItem centroid{-5, -5, 10, 10};
   Notifier notifier;
   int deltaCounter = {};
public:
   explicit View(QWidget *parent = {});
   void addBoard(QPixmap p);
protected:
   Q_SLOT void gotUpdates();
  // void mousePressEvent(QMouseEvent *event) override;
};


#endif // VIEW_H
