#pragma once

#include "Ghost.h"
#include "Player.h"
#include <QGraphicsView>

#define GAME_SPEED 120

class Game:public QGraphicsView {
  Q_OBJECT
private:
  QList<Ghost*> ghosts;
  int timerID{};
public:
  Game();
  Game(QGraphicsScene* scene, int width, int height, const QList<Ghost*>& ghosts, Player* player);
  void timerEvent(QTimerEvent* e) override;
public slots:
  void gameOver();
signals:
    void tick();
};
