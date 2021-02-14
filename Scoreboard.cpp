#include <QFont>
#include "Scoreboard.h"
#include "Game.h"

Scoreboard::Scoreboard() {
  score = 0;
  startTimer(1000/GAME_SPEED);
}

void Scoreboard::timerEvent(QTimerEvent *e) {
  setPlainText(QString("Score: " + QString::number(score)));
  setDefaultTextColor(Qt::white);
  setFont(QFont("times", 16));
}

void Scoreboard::increaseScore(int increment) {
  score += increment;
}

