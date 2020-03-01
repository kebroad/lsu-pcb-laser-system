#include "board.h"


void Board1::setBoardTop(QPixmap p){
    QPixmap pix = p;
    if(this->invert){
    QImage i = p.toImage();
    i.invertPixels();
    pix = pix.fromImage(i);
    }
    setPixmap(pix);
}

/*******************************************************************************/

void Board2::setBoardTop(QPixmap p)
{
    QPixmap pix = p;
    if(this->invert){
    QImage i = p.toImage();
    i.invertPixels();
    pix = pix.fromImage(i);
    }
    setPixmap(pix);
}

void Board2::setBoardSolTop(QPixmap p)
{
    QPixmap pix = p;
    if(!this->invert){
    QImage i = p.toImage();
    i.invertPixels();
    pix = pix.fromImage(i);
    }
    sol_top->setPixmap(pix);
}

QVariant Board2::itemChange(GraphicsItemChange change, const QVariant &value){
    if (change == ItemPositionChange && scene())
    {
        QPointF newPos = value.toPointF();
        this->sol_top->setPos(newPos);
    }
    return QGraphicsItem::itemChange(change, value);


}

/********************************************************************************/

void Board3::setBoardTop(QPixmap p)
{
    QPixmap pix = p;
    if(this->invert){
    QImage i = p.toImage();
    i.invertPixels();
    pix = pix.fromImage(i);
    }
    setPixmap(pix);
}

void Board3::setBoardBot(QPixmap p){
    QPixmap pix = p;
    if(this->invert){
    QImage i = p.toImage();
    i.invertPixels();
    pix = pix.fromImage(i);
    }
    bot->setPixmap(pix);
}

QVariant Board3::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange && scene()) {
        QPointF newPos = value.toPointF();
        this->bot->setPos(newPos);
    }
    return QGraphicsItem::itemChange(change, value);
}

/********************************************************************************/
void Board4::setBoardTop(QPixmap p)
{
    QPixmap pix = p;
    if(this->invert){
    QImage i = p.toImage();
    i.invertPixels();
    pix = pix.fromImage(i);
    }
    setPixmap(pix);
}

void Board4::setBoardBot(QPixmap p){
    QPixmap pix = p;
    if(this->invert){
    QImage i = p.toImage();
    i.invertPixels();
    pix = pix.fromImage(i);
    }
    bot->setPixmap(pix);
}

void Board4::setBoardSolTop(QPixmap p){
    QPixmap pix = p;
    if(!this->invert){
    QImage i = p.toImage();
    i.invertPixels();
    pix = pix.fromImage(i);
    }
    sol_top->setPixmap(pix);
}

void Board4::setBoardSolBot(QPixmap p){
    QPixmap pix = p;
    if(!this->invert){
    QImage i = p.toImage();
    i.invertPixels();
    pix = pix.fromImage(i);
    }
    sol_bot->setPixmap(pix);
}

QVariant Board4::itemChange(GraphicsItemChange change, const QVariant &value){
    if (change == ItemPositionChange && scene()) {
        QPointF newPos = value.toPointF();
        this->bot->setPos(newPos);
        this->sol_bot->setPos(newPos);
        this->sol_top->setPos(newPos);
    }
    return QGraphicsItem::itemChange(change, value);
}
