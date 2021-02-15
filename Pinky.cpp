
#include "Game.h"
#include "Pinky.h"

Pinky::Pinky(qreal x, qreal y, QGraphicsScene* scene, QPointF startingPoint,
			 QString filename)
	: Ghost(x, y, scene, startingPoint, filename) {
	scatterPoint = QPointF(0, 0);
	state = INACTIVE;
	direction = UP;
	timeout = GAME_SPEED * INACTIVITY_SECONDS;
	normal = new QPixmap(":/pinky.png");
}

void Pinky::createTarget() {
	switch (player->getDirection()) {
	case LEFT:
		movementTarget =
			QPointF(player->getCentre().x() - 4 * boundingRect().width(),
					player->getCentre().y());
		break;
	case RIGHT:
		movementTarget =
			QPointF(player->getCentre().x() + 4 * boundingRect().width(),
					player->getCentre().y());
		break;
	case UP:
		movementTarget =
			QPointF(player->getCentre().x(),
					player->getCentre().y() - 4 * boundingRect().height());
		break;
	case DOWN:
		movementTarget =
			QPointF(player->getCentre().x(),
					player->getCentre().y() + 4 * boundingRect().height());
		break;
	}
}
