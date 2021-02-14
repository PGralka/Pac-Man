# include "Wall.h"

#include <QBrush>
#include <QPen>

#define COLOUR Qt::blue

Wall::Wall() = default;

Wall::Wall(qreal x, qreal y, qreal w, qreal h){
      setRect(x, y, w, h);
      setBrush(QBrush(COLOUR));
      setPen(QPen(COLOUR));
};
