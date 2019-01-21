#include "view.h"
#include "notifier.h"
#include <QtWidgets>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>

#include "board.h"
#include <QPixmap>

/******* ORIGINAL STUFF
View::View()
{

}
***********************************/

View::View(QWidget *parent) : QGraphicsView(parent)
{
   centroid.hide();
   centroid.setRotation(45.0);
   centroid.setPen({Qt::blue});
   centroid.setZValue(2);
   scene.addItem(&centroid);
   text.setPos(5, 470);
   text.setZValue(1);
   scene.addItem(&text);
   setRenderHint(QPainter::Antialiasing);
   setScene(&scene);
   setSceneRect(0,0,500,500);
   scene.setProperty(kNotifier, QVariant::fromValue(NotifierPointer(&notifier)));
   connect(&notifier, &Notifier::notification, this, &View::gotUpdates);
   connect(&scene, &QGraphicsScene::selectionChanged, &notifier, &Notifier::notification);
}





void View::gotUpdates()
{
   if (scene.selectedItems().isEmpty()) {
      centroid.hide();
      return;
   }
   centroid.show();
   QPointF centroid;
   qreal area = {};
   for (auto item : scene.selectedItems()) {
      const QRectF r = item->boundingRect();
      const qreal a = r.width() * r.height();
      centroid += item->pos() * a;
      area += a;
   }
   if (area > 0) centroid /= area;
   auto st = QStringLiteral("delta #%1 with %2 items, centroid at %3, %4")
         .arg(deltaCounter++).arg(scene.selectedItems().count())
         .arg(centroid.x(), 0, 'f', 1).arg(centroid.y(), 0, 'f', 1);
   this->centroid.setPos(centroid);
   text.setText(st);
}


void View::addBoard(QPixmap p)
{
    scene.addItem(new Board(QPoint(0,0), p));

}
