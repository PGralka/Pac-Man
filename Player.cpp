#include <QKeyEvent>
#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

#include "Player.h"
#include "Wall.h"
#include "Window.h"
#include "Crossroad.h"
#include "GamePoint.h"
#include "BigGamePoint.h"

Player::Player(qreal x, qreal y, QGraphicsScene* scene){
  direction = LEFT;
  this->scene = scene;
  setPixmap(QPixmap(":/pacman.png").scaled((int)scene->width() / 28 - 1, (int)scene->height() / 31 - 1));
  setPos(x, y);
  setFlag(QGraphicsItem::ItemIsFocusable);
  setFocus();
}

void Player::tick() {
  move();
  checkCollision();
}

void Player::move(){
  processInput();
  switch(direction){
  case LEFT:
    setX(x() - STEP_PL);
    break;
  case RIGHT:
    setX(x() + STEP_PL);
    break;
  case UP:
    setY(y() - STEP_PL);
    break;
  case DOWN:
    setY(y() + STEP_PL);
    break;
  }
  horizontalLoop();
  centre = QPointF((2 * pos().x() + boundingRect().width()) / 2, (2 * pos().y() + boundingRect().height()) / 2);
}

void Player::keyPressEvent(QKeyEvent *e) {
  pressedKey = e->key();
}

bool Player::checkCrossroad() {
  hitbox = QRectF(x(), y(), boundingRect().width(), boundingRect().height());
  QList<QGraphicsItem*> tiles = collidingItems();
  for(auto item : tiles){
    if(typeid(*item) == typeid(Crossroad)){
      if(((Crossroad*)item)->properContains(hitbox)){
        return true;
      }
    }
  }
  return false;
}

void Player::checkCollision(){
  QList<QGraphicsItem*> collisions = collidingItems();
  for(auto item : collisions){
    if(typeid(*item) == typeid(Wall)){
      switch(direction) {
      case LEFT:
        setX(item->boundingRect().right());
        return;
      case RIGHT:
        setX(item->boundingRect().left() - boundingRect().width());
        return;
      case UP:
        setY(item->boundingRect().bottom());
        return;
      case DOWN:
        setY(item->boundingRect().top() - boundingRect().height());
        return;
      }
    }
    else if(typeid(*item) == typeid(GamePoint) || typeid(*item) == typeid(BigGamePoint)){
      ((GamePoint*)item)->getEaten();
      if(typeid(*item) == typeid(BigGamePoint)){
        emit invulnerable();
      }
    }
  }
}

void Player::processInput(){
  prev_dir = direction;
  switch (pressedKey){
  case Qt::Key_Left:
    direction = LEFT;
    break;
  case Qt::Key_Right:
    direction = RIGHT;
    break;
  case Qt::Key_Up:
    direction = UP;
    break;
  case Qt::Key_Down:
    direction = DOWN;
    break;
  }
  if(prev_dir == direction){
    return;
  }
  bool onCrossroad = checkCrossroad();
  if(direction != -prev_dir && !onCrossroad){
    direction = prev_dir;
  }
}
