#pragma once
#include "Blinky.h"
#include "Ghost.h"
class Inky : public Ghost {
  private:
	Blinky* blinky;
	void createTarget() override;

  public:
	Inky(qreal x, qreal y, QGraphicsScene* scene, QPointF startingPoint,
		 Blinky* blinky, QString filename);
};
