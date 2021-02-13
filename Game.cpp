#include "Game.h"
#include <QDebug>
#include <QKeyEvent>

Game::Game() = default;

Game::Game(QGraphicsScene* scene, int width, int height, const QList<Ghost*>& ghosts, Player* player) {
  this->ghosts = ghosts;
  setScene(scene);
  setFixedSize(width, height);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  startTimer(1000/GAME_SPEED);
  for(auto entity : ghosts){
    connect(this, SIGNAL(tick()), entity, SLOT(tick()));
  }
  connect(this, SIGNAL(tick()), player, SLOT(tick()));
}

void Game::timerEvent(QTimerEvent *e) {
  Q_UNUSED(e)
  emit tick();
}
