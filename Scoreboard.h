#pragma once
#include <QGraphicsTextItem>
class Scoreboard:public QGraphicsTextItem {
  Q_OBJECT
private:
  int score;
public:
  Scoreboard();
  void timerEvent(QTimerEvent* e) override;
public slots:
  void increaseScore(int increment);
};
