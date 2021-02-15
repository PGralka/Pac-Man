#include "BigGamePoint.h"
#include <QGraphicsScene>
BigGamePoint::BigGamePoint(qreal x, qreal y, Scoreboard* scoreboard,
						   QGraphicsScene* scene) {
	this->scene = scene;
	setPixmap(QPixmap(":/large.png"));
	setPos(x - boundingRect().width() / 2, y - boundingRect().height() / 2);
	QObject::connect(this, SIGNAL(bigEaten(int)), scoreboard,
					 SLOT(increaseScore(int)));
}

void BigGamePoint::getEaten() {
	emit bigEaten(VALUE);
	scene->removeItem(this);
}
