#pragma once
#include "Ghost.h"
class Blinky:public Ghost {
private:
  void createTarget() override;
public:
  Blinky(qreal x, qreal y, QGraphicsScene* scene, QPointF startingPoint);
};
