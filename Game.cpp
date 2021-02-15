#include "Game.h"
#include <QCoreApplication>
#include <QKeyEvent>

Game::Game() = default;

Game::Game(QGraphicsScene* scene, int width, int height,
		   const QList<Ghost*>& ghosts, Player* player,
		   Scoreboard* scoreboard) {
	this->ghosts = ghosts;
	this->scoreboard = scoreboard;
	setScene(scene);
	setFixedSize(width, height);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	timerID = startTimer(1000 / GAME_SPEED);
	for (auto ghost : ghosts) {
		connect(this, SIGNAL(tick()), ghost, SLOT(tick()));
		connect(ghost, SIGNAL(touchedPlayer()), this, SLOT(gameOver()));
	}
	connect(this, SIGNAL(tick()), player, SLOT(tick()));
}

void Game::timerEvent(QTimerEvent* e) {
	Q_UNUSED(e)
	emit tick();
}

void Game::gameOver() {
	killTimer(timerID);
	time_t start = time(nullptr);
	while (true) {
		if (time(nullptr) - start == 2) {
			break;
		}
	}
	QCoreApplication::quit();
}
