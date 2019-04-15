#ifndef BOARD_H
#define BOARD_H


#include <QGraphicsPixmapItem>
#include <QGraphicsItem>


class Board1 : public QGraphicsPixmapItem
{
public:
    bool invert;
    Board1(QPoint o, bool invert)  {
        setPos(o);
        setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable |
               QGraphicsItem::ItemSendsGeometryChanges);
        this->invert = invert;
   }

   void setBoardTop(QPixmap p);
};


class Board2 : public QGraphicsPixmapItem
{
public:
   bool invert;
   Board2(QPoint o, bool invert)  {
      setPos(o);
      setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable |
               QGraphicsItem::ItemSendsGeometryChanges);
      sol_top = new QGraphicsPixmapItem;
      this->invert = invert;
   }
   void setBoardTop(QPixmap p);
   void setBoardSolTop(QPixmap p);
   QVariant itemChange(GraphicsItemChange change, const QVariant &value);
   QGraphicsPixmapItem* sol_top;
private:

};

class Board3 : public QGraphicsPixmapItem
{
public:
    bool invert;
   Board3(QPoint o, bool invert)  {
      setPos(o);
      setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable |
               QGraphicsItem::ItemSendsGeometryChanges);
      bot = new QGraphicsPixmapItem;
      this->invert = invert;
   }
   void setBoardTop(QPixmap p);
   void setBoardBot(QPixmap p);
   QVariant itemChange(GraphicsItemChange change, const QVariant &value);
   QGraphicsPixmapItem* bot;
private:

};

class Board4 : public QGraphicsPixmapItem
{
public:
    bool invert;
   Board4(QPoint o, bool invert)  {
      setPos(o);
      setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable |
               QGraphicsItem::ItemSendsGeometryChanges);
      bot = new QGraphicsPixmapItem;
      sol_top = new QGraphicsPixmapItem;
      sol_bot = new QGraphicsPixmapItem;
      this->invert = invert;
   }
   void setBoardTop(QPixmap p);
   void setBoardBot(QPixmap p);
   void setBoardSolTop(QPixmap p);
   void setBoardSolBot(QPixmap p);
   QVariant itemChange(GraphicsItemChange change, const QVariant &value);

   QGraphicsPixmapItem* bot;
   QGraphicsPixmapItem* sol_top;
   QGraphicsPixmapItem* sol_bot;
private:

};
#endif // BOARD_H
