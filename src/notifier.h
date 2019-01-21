#ifndef NOTIFIER_H
#define NOTIFIER_H

#include <QObject>
#include <QVariant>
#include <QGraphicsItem>
#include <QPointer>

const char kNotifier[] = "notifier";

class Notifier : public QObject
{
   Q_OBJECT
   int m_count = {};
public:
   int count() const { return m_count; }
   void inc() { m_count ++; }
   void notify() { m_count = {}; emit notification(); }
   Q_SIGNAL void notification();
};

typedef QPointer<Notifier> NotifierPointer;
Q_DECLARE_METATYPE(NotifierPointer)

template <typename T> class NotifyingItem : public T
{
protected:
   QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) override {
      QVariant v;
      if (change == T::ItemPositionHasChanged &&
          this->scene() &&
          (v=this->scene()->property(kNotifier)).isValid())
      {
         auto notifier = v.value<NotifierPointer>();
         notifier->inc();
         if (notifier->count() >= this->scene()->selectedItems().count()) {
            notifier->notify();
         }
      }
      return T::itemChange(change, value);
   }
};




#endif // NOTIFIER_H
