# include "Wall.h"

#include <QBrush>
#include <QPen>

Wall::Wall() = default;

Wall::Wall(qreal x, qreal y, qreal w, qreal h){
      setRect(x, y, w, h);
      setBrush(QBrush(Qt::blue));
      setPen(QPen(Qt::blue));
};
