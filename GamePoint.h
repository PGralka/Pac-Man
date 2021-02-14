#pragma once
#include "Scoreboard.h"
#include <QGraphicsPixmapItem>

// TODO improve gamepoints classes

class GamePoint:public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
protected:
  QGraphicsScene* scene;
private:
  const int VALUE = 10;
public:
  GamePoint() = default;
  GamePoint(qreal x, qreal y, Scoreboard* scoreboard, QGraphicsScene* scene);
  virtual void getEaten();
signals:
  void eaten(int);
};
