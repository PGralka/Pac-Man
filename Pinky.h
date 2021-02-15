#pragma once
#include "Ghost.h"

class Pinky : public Ghost {
  private:
	void createTarget() override;

  public:
	Pinky(qreal x, qreal y, QGraphicsScene* scene, QPointF startingPoint,
		  QString filename);
};
