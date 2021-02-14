
#include "Inky.h"
#include "Blinky.h"
#include "Game.h"
#include <cmath>

Inky::Inky(qreal x, qreal y, QGraphicsScene *scene, QPointF startingPoint, Blinky* blinky) {
  srand(time(nullptr));
  this->scene = scene;
  this->startingPoint = startingPoint;
  this->blinky = blinky;
  scatterPoint = QPointF(scene->width(), scene->height());
  state = INACTIVE;
  direction = RIGHT;
  timeout = 2 * GAME_SPEED * INACTIVITY_SECONDS;
  normal = new QPixmap(":/inky.png");
  setPixmap(normal->scaled((int)scene->width() / 28 - 1, (int)scene->height() / 31 - 1));
  setPos(x, y);
}

void Inky::createTarget() {
  QPointF symmetryPoint;
  switch(player->getDirection()){
  case LEFT:
    symmetryPoint = QPointF(player->getCentre().x() - 2 * boundingRect().width(), player->getCentre().y());
    break;
  case RIGHT:
    symmetryPoint = QPointF(player->getCentre().x() + 2 * boundingRect().width(), player->getCentre().y());
    break;
  case UP:
    symmetryPoint = QPointF(player->getCentre().x(), player->getCentre().y() - 2 * boundingRect().height());
    break;
  case DOWN:
    symmetryPoint = QPointF(player->getCentre().x() , player->getCentre().y() + 2 * boundingRect().height());
    break;
  }
  movementTarget = QPointF(2 * symmetryPoint.x() - blinky->getCentre().x(), 2 * symmetryPoint.y() - blinky->getCentre().y());
}
