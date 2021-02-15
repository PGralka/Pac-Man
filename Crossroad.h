#pragma once

#include <QGraphicsRectItem>

class Crossroad : public QGraphicsRectItem {
  public:
	Crossroad();
	Crossroad(qreal x, qreal y, qreal w, qreal h);
	bool properContains(QRectF r);
};
