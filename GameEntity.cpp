#include "GameEntity.h"

void GameEntity::horizontalLoop(){
  if(x() + boundingRect().width() <= 0 && direction == LEFT){
    setX(scene->width());
  }
  else if(x() >= scene->width() && direction == RIGHT){
    setX(-boundingRect().width());
  }
}
QPointF GameEntity::getCentre() {
  return centre;
}
