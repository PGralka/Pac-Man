#pragma once
#include "Crossroad.h"
#include "GameEntity.h"
#include "Player.h"

#define INACTIVITY_SECONDS 6

class Ghost : public GameEntity {
	Q_OBJECT
  protected:
	enum states {
		PREPARE = -2,
		INACTIVE = -1,
		CHASE = 0,
		SCATTER = 1,
		EATEN = 2,
		FRIGHTENED = 3
	};
	const int VALUE = 1000;
	int timeout{}, state{}, prevState{}, counter = 0, frightenTime = 0;
	bool wallCollision = false;
	QPointF movementTarget, scatterPoint, startingPoint;
	Player* player{};
	QGraphicsRectItem* predictedTile{};
	Crossroad* lastCrossroad;
	QPixmap* normal{};
	QPixmap* scared = new QPixmap(":/frightened.png");
	QPixmap* eaten = new QPixmap(":/eaten.png");
	int wallDirection = 0, prevWallDirection = 0;
	Ghost(qreal x, qreal y, QGraphicsScene* scene, QPointF startingPoint,
		  QString filename);
	double calculateDistance(int direction);
	void decideDirection();
	bool handleCollision();
	bool isOnCrossroad();
	void move() override;
	virtual void createTarget() = 0;

  public:
	void setPlayer(Player* player);
  public slots:
	void tick() override;
	void frighten();
  signals:
	void touchedPlayer();
	void eatenSignal(int);
};
