#ifndef BOARD_H
#define BOARD_H





#include "notifier.h"
//#include "view.h"



class Board : public NotifyingItem<QGraphicsPixmapItem>
{
  // QBrush m_brush;
public:
   Board(const QPointF & c, QPixmap p)  {
      //const qreal r = 10.0 + (50.0*qrand())/RAND_MAX;
      //setRect({-r, -r, 2.0*r, 2.0*r});
      setPos(c);
      setPixmap(p);
      setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable |
               QGraphicsItem::ItemSendsGeometryChanges);

   }
};



#endif // BOARD_H
