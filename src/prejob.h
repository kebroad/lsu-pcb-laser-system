#ifndef PREJOB_H
#define PREJOB_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include <QObject>


class PreJob : public QObject
{
    Q_OBJECT
public:
    explicit PreJob(QObject *parent = nullptr);
    QGraphicsScene * top_scene = new QGraphicsScene;
    QGraphicsScene * bot_scene = new QGraphicsScene;
    QGraphicsScene * stop_scene = new QGraphicsScene;
    QGraphicsScene * sbot_scene = new QGraphicsScene;

    //QGraphicsItem** top_pix = new QGraphicsItem*[10];
    QGraphicsItem* bot_pix = new QGraphicsPixmapItem[10];
    QGraphicsItem* stop_pix = new QGraphicsPixmapItem[10];
    QGraphicsItem* sbop_pix = new QGraphicsPixmapItem[10];

    qreal height = 1500;
    qreal width  = 1000;
signals:

public slots:
};

#endif // PREJOB_H
