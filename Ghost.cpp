#include <cmath>

#include "Ghost.h"
#include "Crossroad.h"
#include "Wall.h"
#include "Game.h"
#include <QDebug>

#define PHASE_TIME 7
#define FRIGHTEN_TIME 10
#define DIRECTION_UNAVAILABLE std::numeric_limits<double>::max()

void Ghost::tick() {
  if(state != FRIGHTENED){
    counter++;
    if(counter % (GAME_SPEED * PHASE_TIME) == 0){
      counter -= (GAME_SPEED * PHASE_TIME);
      if(state == CHASE){
        state = SCATTER;
      }
      else if(state == SCATTER){
        state = CHASE;
      }
      direction = -direction;
      prev_dir = -direction;
    }
  }
  else if (state == FRIGHTENED){
    ++frightenTime;
    if(frightenTime % (GAME_SPEED * FRIGHTEN_TIME) == 0){
      frightenTime = 0;
      state = prevState;
      setPixmap(normal->scaled((int)scene->width() / 28 - 1, (int)scene->height() / 31 - 1));
    }
  }
  move();
}

double Ghost::calculateDistance(int direction) {
  predictedTile = new QGraphicsRectItem(0, 0, boundingRect().width(), boundingRect().height());
  switch(direction){
  case LEFT:
    predictedTile->setPos(x() - boundingRect().width(), y());
    break;
  case RIGHT:
    predictedTile->setPos(x() + boundingRect().width(), y());
    break;
  case UP:
    predictedTile->setPos(x(), y() - boundingRect().height());
    break;
  case DOWN:
    predictedTile->setPos(x(), y() + boundingRect().height());
    break;
  }
  centre = QPointF((2 * predictedTile->x() + predictedTile->boundingRect().width()) / 2, (2 * predictedTile->y() + predictedTile->boundingRect().height()) / 2);
  double temp;
  if(state == CHASE){
    temp = sqrt(pow(centre.x() - movementTarget.x(), 2) + pow(centre.y() - movementTarget.y(), 2));
  }
  else{
    temp = sqrt(pow(centre.x() - scatterPoint.x(), 2) + pow(centre.y() - scatterPoint.y(), 2));
  }
  delete predictedTile;
  return temp;
}

void Ghost::decideDirection() {
  createTarget();
  double distanceToTarget[5];
  movementTarget = player->getCentre();
  if(!wallCollision){
    prev_dir = direction;
  }
  else{
    direction = prev_dir;
  }
  for(int i = UP; i <= DOWN; ++i){
    if(i == 0){
      distanceToTarget[i + 2] = DIRECTION_UNAVAILABLE;
      continue;
    }
    if(i == -direction){
      distanceToTarget[i + 2] = DIRECTION_UNAVAILABLE;
    }
    else if(wallCollision && (i == wallDirection || i == prevWallDirection)){
      distanceToTarget[i + 2] = DIRECTION_UNAVAILABLE;
    }
    else{
      distanceToTarget[i + 2] = calculateDistance(i);
    }
  }
  double minDistance = DIRECTION_UNAVAILABLE;
  if(state != FRIGHTENED){
    for(double distance : distanceToTarget){
      if(minDistance > distance){
        minDistance = distance;
      }
    }
  }
  if(state == FRIGHTENED){
    int random;
    while(true){
      random = rand() % 5;
      if(distanceToTarget[random] != DIRECTION_UNAVAILABLE){
        direction = random - 2;
        return;
      }
    }
  }
  else{
    for(int i = 0; i < 5; ++i){
      if(minDistance == distanceToTarget[i]){
        direction = i - 2;
        return;
      }

    }
  }
}

bool Ghost::isCollidingWall() {
  QList<QGraphicsItem*> list = collidingItems();
  for(auto item : list){
    if(typeid(*item) == typeid(Wall)){
      switch(direction) {
      case LEFT:
        setX(item->boundingRect().right());
        return true;
      case RIGHT:
        setX(item->boundingRect().left() - boundingRect().width());
        return true;
      case UP:
        setY(item->boundingRect().bottom());
        return true;
      case DOWN:
        setY(item->boundingRect().top() - boundingRect().height());
        return true;
      }
    }
  }
  return false;
}

bool Ghost::isOnCrossroad() {
  QList<QGraphicsItem*> tiles = collidingItems();
  auto tempHitbox = new QRectF(x(), y(), boundingRect().width(), boundingRect().height());
  bool isOnCrossroadFlag = false;
  for(auto tile : tiles){
    if(typeid(*tile) == typeid(Crossroad)){
      if(((Crossroad*)tile)->properContains(*tempHitbox) && (tile != lastCrossroad || wallCollision)){
        isOnCrossroadFlag = true;
        lastCrossroad = (Crossroad*)tile;
        break;
      }
    }
  }
  delete tempHitbox;
  return isOnCrossroadFlag;
}

void Ghost::setPlayer(Player *playerPtr) {
  this->player = playerPtr;
}

void Ghost::move() {
  if(isOnCrossroad()){
    decideDirection();
  }
  switch(direction){
  case LEFT:
    setX(x() - STEP_GH);
    break;
  case RIGHT:
    setX(x() + STEP_GH);
    break;
  case UP:
    setY(y() - STEP_GH);
    break;
  case DOWN:
    setY(y() + STEP_GH);
    break;
  }
  wallCollision = isCollidingWall();
  if(wallCollision){
    if(wallDirection != 0){
      prevWallDirection = wallDirection;
    }
    wallDirection = direction;
  }
  else{
    wallDirection = 0;
    prevWallDirection = 0;
  }
  horizontalLoop();
}

void Ghost::frighten() {
  prevState = state;
  state = FRIGHTENED;
  prev_dir = direction;
  direction = -direction;
  setPixmap(scared->scaled((int)scene->width() / 28 - 1, (int)scene->height() / 31 - 1));
  frightenTime = 0;
}
