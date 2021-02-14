#pragma once
#include "Ghost.h"
class Clyde:public Ghost {
private:
  void createTarget() override;
public:
  Clyde(qreal x, qreal y, QGraphicsScene* scene, QPointF startingPoint);
};
