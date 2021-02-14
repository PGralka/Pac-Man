
#include "Blinky.h"

#include <QWidget>
#include <QDebug>

Blinky::Blinky(qreal x, qreal y, QGraphicsScene* scene, QPointF startingPoint) {
  srand(time(nullptr));
  this->scene = scene;
  this->startingPoint = startingPoint;
  direction = LEFT;
  scatterPoint = QPointF(scene->width(), 0);
  state = CHASE;
  normal = new QPixmap(":/blinky.png");
  timeout = 0;
  setPixmap(normal->scaled((int)scene->width() / 28 - 1, (int)scene->height() / 31 - 1));
  setPos(x, y);
}

void Blinky::createTarget() {
  movementTarget = player->getCentre();
}
