#pragma once

#include "GameEntity.h"
#include <QGraphicsPixmapItem>
#include <QObject>

class Player: public GameEntity {
  Q_OBJECT
private:
  QRectF hitbox{};
  int prev_dir{}, pressedKey{};
  void processInput();
public:
  explicit Player(qreal x, qreal y, QGraphicsScene* scene);
  void move() override;
  void keyPressEvent(QKeyEvent* e) override;
  void keyReleaseEvent(QKeyEvent* e) override;
  void checkCollision();
  bool checkCrossroad();
  int getDirection();
public slots:
  void tick() override;
signals:
  void invulnerable();
};
