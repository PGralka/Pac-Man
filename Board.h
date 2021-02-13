#pragma once

#include "Ghost.h"
#include "Player.h"
#include <QGraphicsItem>
#include <QList>

class Board {
private:
  QList<QGraphicsItem*> board;
  QList<Ghost*> ghosts;
  Player* player{};
  void prepareBoard(QGraphicsScene* scene);
public:
  Board();
  explicit Board(QGraphicsScene* scene);
  Player* getPlayer();
  QList<Ghost*> getGhosts();
};
