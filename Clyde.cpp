
#include "Clyde.h"
#include "Game.h"
#include <cmath>

#define RANGE 16

Clyde::Clyde(qreal x, qreal y, QGraphicsScene* scene, QPointF startingPoint,
			 QString filename)
	: Ghost(x, y, scene, startingPoint, filename) {
	scatterPoint = QPointF(0, scene->height());
	state = INACTIVE;
	direction = LEFT;
	normal = new QPixmap(":/clyde.png");
	timeout = 3 * GAME_SPEED * INACTIVITY_SECONDS;
}

void Clyde::createTarget() {
	double radius = std::sqrt(pow(boundingRect().width() * 0.5, 2) +
							  pow(boundingRect().height() * 0.5, 2));
	double distance = calculateDistance(0);
	if (distance < RANGE * radius) {
		movementTarget = scatterPoint;
	} else {
		movementTarget = player->getCentre();
	}
}
