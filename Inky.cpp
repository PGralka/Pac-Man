
#include "Blinky.h"
#include "Game.h"
#include "Inky.h"
#include <cmath>

Inky::Inky(qreal x, qreal y, QGraphicsScene* scene, QPointF startingPoint,
		   Blinky* blinky, QString filename)
	: Ghost(x, y, scene, startingPoint, filename) {
	this->blinky = blinky;
	scatterPoint = QPointF(scene->width(), scene->height());
	state = INACTIVE;
	direction = RIGHT;
	timeout = 2 * GAME_SPEED * INACTIVITY_SECONDS;
	normal = new QPixmap(":/inky.png");
}

void Inky::createTarget() {
	QPointF symmetryPoint;
	switch (player->getDirection()) {
	case LEFT:
		symmetryPoint =
			QPointF(player->getCentre().x() - 2 * boundingRect().width(),
					player->getCentre().y());
		break;
	case RIGHT:
		symmetryPoint =
			QPointF(player->getCentre().x() + 2 * boundingRect().width(),
					player->getCentre().y());
		break;
	case UP:
		symmetryPoint =
			QPointF(player->getCentre().x(),
					player->getCentre().y() - 2 * boundingRect().height());
		break;
	case DOWN:
		symmetryPoint =
			QPointF(player->getCentre().x(),
					player->getCentre().y() + 2 * boundingRect().height());
		break;
	}
	movementTarget = QPointF(2 * symmetryPoint.x() - blinky->getCentre().x(),
							 2 * symmetryPoint.y() - blinky->getCentre().y());
}
