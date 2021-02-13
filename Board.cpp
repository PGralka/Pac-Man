#include "Board.h"
#include "BigGamePoint.h"
#include "Blinky.h"
#include "Crossroad.h"
#include "GamePoint.h"
#include "Player.h"
#include "Scoreboard.h"
#include "Wall.h"

#include <QDebug>
#include <QGraphicsScene>
#include <QWidget>

#define WALL 'w'
#define CROSSROAD 'r'
#define CROSSROAD_WITH_PELLET 'c'
#define CROSSROAD_WITH_BIG_PELLET 'C'
#define PLAYER 'P'
#define PELLET '*'
#define BIG_PELLET 'O'
#define BLINKY 'b'

Board::Board() = default;

Board::Board(QGraphicsScene* scene) {
  prepareBoard(scene);
  for(auto item : board){
    scene->addItem(item);
  }
}

void Board::prepareBoard(QGraphicsScene* scene){
  const std::string layout[] = {{"wwwwwwwwwwwwwwwwwwwwwwwwwwww"},
                                {"wc****c*****cwwc*****c****cw"},
                                {"w*wwww*wwwww*ww*wwwww*wwww*w"},
                                {"wOwwww*wwwww*ww*wwwww*wwwwOw"},
                                {"w*wwww*wwwww*ww*wwwww*wwww*w"},
                                {"wc****c**c**c**c**c**c****cw"},
                                {"w*wwww*ww*wwwwwwww*ww*wwww*w"},
                                {"w*wwww*ww*wwwwwwww*ww*wwww*w"},
                                {"wc****cwwc**cwwc**cwwc****cw"},
                                {"wwwwww*wwwww ww wwwww*wwwwww"},
                                {"wwwwww*wwwww ww wwwww*wwwwww"},
                                {"wwwwww*wwr  rb r  rww*wwwwww"},
                                {"wwwwww*ww www  www ww*wwwwww"},
                                {"wwwwww*ww w      w ww*wwwwww"},
                                {"******c  rwi p g wr  c******"},
                                {"wwwwww*ww w      w ww*wwwwww"},
                                {"wwwwww*ww wwwwwwww ww*wwwwww"},
                                {"wwwwww*wwr        rww*wwwwww"},
                                {"wwwwww*ww wwwwwwww ww*wwwwww"},
                                {"wwwwww*ww wwwwwwww ww*wwwwww"},
                                {"wc****c**c**cwwc**c**c****cw"},
                                {"w*wwww*wwwww*ww*wwwww*wwww*w"},
                                {"w*wwww*wwwww*ww*wwwww*wwww*w"},
                                {"wC*cwwc**c**cP c**c**cwwc*Cw"},
                                {"www*ww*ww*wwwwwwww*ww*ww*www"},
                                {"www*ww*ww*wwwwwwww*ww*ww*www"},
                                {"wc*c**cwwc**cwwc**cwwc**c*cw"},
                                {"w*wwwwwwwwww*ww*wwwwwwwwww*w"},
                                {"w*wwwwwwwwww*ww*wwwwwwwwww*w"},
                                {"wc**********c**c**********cw"},
                                {"wwwwwwwwwwwwwwwwwwwwwwwwwwww"}};
  std::string temp;
  qreal w = scene->width()/28;
  qreal h = scene->height()/31;
  auto scoreboard = new Scoreboard();
  Blinky* blinky;
  for(int i = 0; i < 31; ++i){
    temp = layout[i];
    for(int j = 0; j < temp.length(); ++j){
      switch (temp.at(j)) {
      case WALL:
        board.append(new Wall(j * w, i * h, w, h));
        break;
      case PLAYER:
        player = new Player(j * w, i * h + 1, scene);
        for(Ghost* entity : ghosts){
          entity->setPlayer(player);
          QWidget::connect(player, SIGNAL(invulnerable()), entity, SLOT(frighten()));
        }
        break;
      case BLINKY:
        blinky = new Blinky(j * w, i * h + 1, scene);
        ghosts.append(blinky);
        break;
      case CROSSROAD:
        board.append(new Crossroad(j * w + 1, i * h + 1, w - 1, h - 1));
        break;
      case CROSSROAD_WITH_PELLET:
        board.append(new Crossroad(j * w + 1, i * h + 1, w - 1, h - 1));
        board.append(new GamePoint((j + 0.5) * w, (i + 0.5) * h, scoreboard, scene));
        break;
      case CROSSROAD_WITH_BIG_PELLET:
        board.append(new Crossroad(j * w + 1, i * h + 1, w - 1, h - 1));
        board.append(new BigGamePoint((j + 0.5) * w, (i + 0.5) * h, scoreboard, scene));
        break;
      case BIG_PELLET:
        board.append(new BigGamePoint((j + 0.5) * w, (i + 0.5) * h, scoreboard, scene));
        break;
      case PELLET:
        board.append(new GamePoint((j + 0.5) * w, (i + 0.5) * h, scoreboard, scene));
      }
    }
  }
  board.append(scoreboard);
  board.append(player);
  board.append(blinky);
}

Player* Board::getPlayer(){
  return player;
}
QList<Ghost*> Board::getGhosts(){
return ghosts;
}
