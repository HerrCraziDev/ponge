#ifndef DEF_PONGE_SUP
#define DEF_PONGE_SUP

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
//#include "Player.hpp"
#include "Ball.hpp"
#include "constants.hpp"

class Paddle
{

public:
  Paddle(QGraphicsScene *scene, int pID = 1);

  int x() { return paddle->x(); }
  int y() { return paddle->y(); }
  int h() { return PADDLE_HEIGTH; }
  int w() { return PADDLE_WIDTH; }

  bool collide(QGraphicsEllipseItem *ball, QGraphicsLineItem *collider);
  bool collideLeft(QGraphicsEllipseItem *q_ball);
  bool collideRight(QGraphicsEllipseItem *q_ball);
  bool collideUp(QGraphicsEllipseItem *q_ball);
  bool collideDown(QGraphicsEllipseItem *q_ball);
  bool collideHorizontalSide(QGraphicsEllipseItem *q_ball);
  bool collideVerticalSide(QGraphicsEllipseItem *q_ball);

  void moveUp(int delta = 1);
  void moveDown(int delta = 1);

  void brake();

  void update();

private:
    QGraphicsRectItem *paddle;

    QGraphicsLineItem *upCollision;
    QGraphicsLineItem *downCollision;
    QGraphicsLineItem *leftCollision;
    QGraphicsLineItem *rightCollision;

    float velocity = 0;

    bool hasCollided = false;
};

#endif