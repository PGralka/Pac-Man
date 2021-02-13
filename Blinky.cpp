
#include "Blinky.h"

#include <QWidget>
#include <QDebug>

Blinky::Blinky(qreal x, qreal y, QGraphicsScene* scene) {
  srand(time(nullptr));
  this->scene = scene;
  direction = LEFT;
  scatterPoint = QPointF(scene->width(), 0);
  state = CHASE;
  normal = new QPixmap(":/blinky.png");
  setPixmap(normal->scaled((int)scene->width() / 28 - 1, (int)scene->height() / 31 - 1));
  setPos(x, y);
}

void Blinky::createTarget() {
  movementTarget = player->getCentre();
}
