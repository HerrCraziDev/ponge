#ifndef DEF_PONGE_SUP
#define DEF_PONGE_SUP

#include <QGraphicsScene>
#include <QGraphicsRectItem>
//#include "Player.hpp"
#include "Ball.hpp"
#include "constants.hpp"

class Paddle
{

public:
  Paddle(QGraphicsScene *scene, int pID = 1);

  bool collideLeft(Ball &ball);
  bool collideRight(Ball &ball);
  bool collideUp(Ball &ball);
  bool collideDown(Ball &ball);
  bool collideHorizontalSide(Ball &ball);
  bool collideVerticalSide(Ball &ball);

  void moveUp(int dep = 1);
  void moveDown(int dep = 1);

private:
    QGraphicsRectItem *paddle;

    QGraphicsLineItem *UL_collision;
    QGraphicsLineItem *DL_collision;
    QGraphicsLineItem *UR_collision;
    QGraphicsLineItem *DR_collision;
};

#endif