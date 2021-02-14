
#include "Pinky.h"
#include "Game.h"
#include <QDebug>

Pinky::Pinky(qreal x, qreal y, QGraphicsScene *scene, QPointF startingPoint) {
  srand(time(nullptr));
  this->scene = scene;
  this->startingPoint = startingPoint;
  scatterPoint = QPointF(0, 0);
  state = INACTIVE;
  direction = UP;
  timeout = GAME_SPEED * INACTIVITY_SECONDS;
  normal = new QPixmap(":/pinky.png");
  setPixmap(normal->scaled((int)scene->width() / 28 - 1, (int)scene->height() / 31 - 1));
  setPos(x, y);
}

void Pinky::createTarget() {
  switch(player->getDirection()){
  case LEFT:
    movementTarget = QPointF(player->getCentre().x() - 4 * boundingRect().width(), player->getCentre().y());
    break;
  case RIGHT:
    movementTarget = QPointF(player->getCentre().x() + 4 * boundingRect().width(), player->getCentre().y());
    break;
  case UP:
    movementTarget = QPointF(player->getCentre().x(), player->getCentre().y() - 4 * boundingRect().height());
    break;
  case DOWN:
    movementTarget = QPointF(player->getCentre().x() , player->getCentre().y() + 4 * boundingRect().height());
    break;
  }
}