#include "Crossroad.h"

#include <QBrush>

Crossroad::Crossroad() = default;

Crossroad::Crossroad(qreal x, qreal y, qreal w, qreal h) {
  setRect(x, y, w, h);
}
bool Crossroad::properContains(QRectF& r) {
  if(boundingRect().top() <= r.top() && boundingRect().bottom() >= r.bottom() && boundingRect().left() <= r.left() && boundingRect().right() >= r.right()){
    return true;
  }
  return false;
}
