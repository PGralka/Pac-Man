#pragma once

#include "Ghost.h"
#include "Player.h"
#include "Scoreboard.h"
#include <QGraphicsItem>
#include <QList>

class Board {
  private:
	QList<QGraphicsItem*> board;
	QList<Ghost*> ghosts;
	Player* player{};
	Scoreboard* scoreboard;
	void prepareBoard(QGraphicsScene* scene);

  public:
	Board();
	explicit Board(QGraphicsScene* scene);
	Player* getPlayer();
	QList<Ghost*> getGhosts();
	Scoreboard* getScoreboard();
};
