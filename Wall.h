#pragma once

#include <QGraphicsRectItem>

class Wall : public QGraphicsRectItem {
public:
  Wall();
  Wall(qreal x, qreal y, qreal w, qreal h);
};
