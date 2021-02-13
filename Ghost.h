#pragma once
#include "Crossroad.h"
#include "GameEntity.h"
#include "Player.h"

class Ghost:public GameEntity {
  Q_OBJECT
protected:
  enum states{
    CHASE = 0,
    SCATTER = 1,
    EATEN = 2,
    FRIGHTENED = 3
  };
  int state, prevState, counter = 0, frightenTime;
  bool wallCollision = false;
  QPointF movementTarget, scatterPoint;
  Player* player;
  QGraphicsRectItem* predictedTile;
  Crossroad* lastCrossroad;
  QPixmap* normal;
  QPixmap* scared = new QPixmap(":/frightened.png");
  int wallDirection = 0, prevWallDirection = 0;
  double calculateDistance(int direction);
  void decideDirection();
  bool isCollidingWall();
  bool isOnCrossroad();
  void move() override;
  virtual void createTarget()=0;
public:
  void setPlayer(Player* player);
public slots:
  void tick() override;
  void frighten();
};
