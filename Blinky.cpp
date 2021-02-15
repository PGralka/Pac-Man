
#include "Blinky.h"

#include <QWidget>

Blinky::Blinky(qreal x, qreal y, QGraphicsScene* scene, QPointF startingPoint,
			   QString filename)
	: Ghost(x, y, scene, startingPoint, filename) {
	direction = LEFT;
	scatterPoint = QPointF(scene->width(), 0);
	state = CHASE;
	timeout = 0;
}

void Blinky::createTarget() { movementTarget = player->getCentre(); }
