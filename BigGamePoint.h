#pragma once
#include "GamePoint.h"
class BigGamePoint : public GamePoint {
	Q_OBJECT
  private:
	const int VALUE = 100;

  public:
	BigGamePoint(qreal x, qreal y, Scoreboard* scoreboard,
				 QGraphicsScene* scene);
	void getEaten() override;
  signals:
	void bigEaten(int);
};
