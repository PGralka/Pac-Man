
#include "Clyde.h"
#include <QDebug>
#include "Game.h"
#include <cmath>

#define RANGE 16

Clyde::Clyde(qreal x, qreal y, QGraphicsScene *scene, QPointF startingPoint) {
  srand(time(nullptr));
  this->scene = scene;
  this->startingPoint = startingPoint;
  scatterPoint = QPointF(0, scene->height());
  state = INACTIVE;
  direction = LEFT;
  normal = new QPixmap(":/clyde.png");
  timeout = 3 * GAME_SPEED * INACTIVITY_SECONDS;
  setPixmap(normal->scaled((int)scene->width() / 28 - 1, (int)scene->height() / 31 - 1));
  setPos(x, y);
}

void Clyde::createTarget() {
  double radius = std::sqrt(pow(boundingRect().width() * 0.5, 2) + pow(boundingRect().height() * 0.5, 2));
  double distance = calculateDistance(0);
  if(distance < RANGE * radius){
    movementTarget = scatterPoint;
  }
  else{
    movementTarget = player->getCentre();
  }
}