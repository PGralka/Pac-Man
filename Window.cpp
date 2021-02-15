#include "Board.h"
#include "Game.h"
#include "Window.h"
#include <QCoreApplication>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QVBoxLayout>

QGraphicsScene* prepareScene(int width, int height);

Window::Window() = default;

Window::Window(int width, int height) {
	auto* scene = prepareScene(width, height);
	board = Board(scene);
	auto* game = new Game(scene, width, height, board.getGhosts(),
						  board.getPlayer(), board.getScoreboard());
	game->show();
}

QGraphicsScene* prepareScene(int width, int height) {
	auto* scene = new QGraphicsScene();
	scene->setBackgroundBrush(QBrush(Qt::black));
	scene->setSceneRect(0, 0, width, height);
	return scene;
}
