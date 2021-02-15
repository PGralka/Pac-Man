#include "GamePoint.h"
#include <QGraphicsScene>

GamePoint::GamePoint(qreal x, qreal y, Scoreboard* scoreboard,
					 QGraphicsScene* scene) {
	this->scene = scene;
	setPixmap(QPixmap(":/small.png"));
	setPos(x - boundingRect().width() / 2, y - boundingRect().height() / 2);
	QObject::connect(this, SIGNAL(eaten(int)), scoreboard,
					 SLOT(increaseScore(int)));
}

void GamePoint::getEaten() {
	emit eaten(VALUE);
	scene->removeItem(this);
}
