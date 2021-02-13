#pragma once
#include "Ghost.h"
class Blinky:public Ghost {
public:
  Blinky(qreal x, qreal y, QGraphicsScene* scene);
  void createTarget() override;
};
