#ifndef BOARD_H
#define BOARD_H





#include "notifier.h"
//#include "view.h"



class board_1 : public QGraphicsPixmapItem
{
public:
   board_1()  {
      setPos(QPointF(0,0));
      setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable |
               QGraphicsItem::ItemSendsGeometryChanges);
   }
   void setBoardTop(QPixmap p);
};


class board_2 : public QGraphicsPixmapItem
{
public:
   board_2()  {
      setPos(QPointF(0,0));
      setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable |
               QGraphicsItem::ItemSendsGeometryChanges);
   }
   void setBoardTop(QPixmap p);
   void setBoardSolTop(QPixmap p);
   QVariant itemChange(GraphicsItemChange change, const QVariant &value);
private:
   QGraphicsPixmapItem sol_top;
};

class board_3 : public QGraphicsPixmapItem
{
public:
   board_3()  {
      setPos(QPointF(0,0));
      setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable |
               QGraphicsItem::ItemSendsGeometryChanges);
   }
   void setBoardTop(QPixmap p);
   void setBoardBot(QPixmap p);
   QVariant itemChange(GraphicsItemChange change, const QVariant &value);
private:
   QGraphicsPixmapItem bot;
};

class board_4 : public QGraphicsPixmapItem
{
public:
   board_4()  {
      setPos(QPointF(0,0));
      setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable |
               QGraphicsItem::ItemSendsGeometryChanges);
   }
   void setBoardTop(QPixmap p);
   void setBoardBot(QPixmap p);
   void setBoardSolTop(QPixmap p);
   void setBoardSolBot(QPixmap p);
   QVariant itemChange(GraphicsItemChange change, const QVariant &value);
private:
   QGraphicsPixmapItem bot;
   QGraphicsPixmapItem sol_top;
   QGraphicsPixmapItem sol_bot;
};
#endif // BOARD_H
