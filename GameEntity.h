#pragma once
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
class GameEntity: public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
protected:
  QPointF centre;
  int prev_dir;
  const int STEP_PL = 1;
  const double STEP_GH = 1.1;
  enum directions {
    LEFT = -1,
    RIGHT = 1,
    UP = -2,
    DOWN = 2
  };
  int direction;
  QGraphicsScene* scene;
public:
  virtual void move()=0;
  QPointF getCentre();
  void horizontalLoop();
public slots:
  virtual void tick()=0;
};
