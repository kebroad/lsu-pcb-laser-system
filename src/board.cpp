#include "board.h"


void Board1::setBoardTop(QPixmap p){
    setPixmap(p);
}

/*******************************************************************************/

void Board2::setBoardTop(QPixmap p){
    setPixmap(p);
}

void Board2::setBoardSolTop(QPixmap p){
    sol_top.setPixmap(p);
}

QVariant Board2::itemChange(GraphicsItemChange change, const QVariant &value){
    if (change == ItemPositionChange && scene()) {
        QPointF newPos = value.toPointF();
        this->sol_top.setPos(newPos);
    }
    return QGraphicsItem::itemChange(change, value);


}

/********************************************************************************/

void Board3::setBoardTop(QPixmap p){
    setPixmap(p);
}

void Board3::setBoardBot(QPixmap p){
    bot.setPixmap(p);
}

QVariant Board3::itemChange(GraphicsItemChange change, const QVariant &value){
    if (change == ItemPositionChange && scene()) {
        QPointF newPos = value.toPointF();
        this->bot.setPos(newPos);
    }
    return QGraphicsItem::itemChange(change, value);
}

/********************************************************************************/
void Board4::setBoardTop(QPixmap p){
    setPixmap(p);
}

void Board4::setBoardBot(QPixmap p){
    bot.setPixmap(p);
}

void Board4::setBoardSolTop(QPixmap p){
    sol_top.setPixmap(p);
}

void Board4::setBoardSolBot(QPixmap p){
    sol_bot.setPixmap(p);
}

QVariant Board4::itemChange(GraphicsItemChange change, const QVariant &value){
    if (change == ItemPositionChange && scene()) {
        QPointF newPos = value.toPointF();
        this->bot.setPos(newPos);
        this->sol_bot.setPos(newPos);
        this->sol_top.setPos(newPos);
    }
    return QGraphicsItem::itemChange(change, value);
}
