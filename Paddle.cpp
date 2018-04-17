#include "Paddle.hpp"

Paddle::Paddle(QGraphicsScene *scene, int pID = 1)
{
    int x_init;

    if ( pID == 1 ) x_init = 10;
    else x_init = BOARD_WIDTH - PADDLE_WIDTH - 10;

    paddle = scene->addRect(10, BOARD_HEIGHT / 2 - PADDLE_HEIGTH / 2, PADDLE_WIDTH, PADDLE_HEIGTH, QPen(Qt::white), QBrush(Qt::white));

    DL_collision = scene->addLine(0,0,10,10,QPen(Qt::red));
}