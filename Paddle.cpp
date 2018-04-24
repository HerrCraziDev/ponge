#include "Paddle.hpp"

Paddle::Paddle(QGraphicsScene *scene, int pID)
{
    int x_init;

    if ( pID == 1 ) x_init = 10;
    else x_init = BOARD_WIDTH - PADDLE_WIDTH - 10;

    paddle = scene->addRect(0, 0, PADDLE_WIDTH, PADDLE_HEIGTH, QPen(Qt::white), QBrush(Qt::white));

    upCollision = scene->addLine(x(), y(), x() + w(), y(), QPen(Qt::red));
    downCollision = scene->addLine(x(), y() + h(), x() + w(), y() + h(), QPen(Qt::red));
    leftCollision = scene->addLine(x(), y(), x(), y() + h(), QPen(Qt::red));
    rightCollision = scene->addLine(x() + w(), y(), x() + w(), y() + h(), QPen(Qt::red));

    paddle->setPos(x_init, BOARD_HEIGHT / 2 - PADDLE_HEIGTH / 2);

    qDebug() << "Paddle at " << x() << ", " << y();
}

bool Paddle::collideUp(QGraphicsEllipseItem *q_ball)
{
    if ( q_ball->collidesWithItem(upCollision) && !hasCollided )
    {
        hasCollided = true;
        return true;
    }
    return false;
}

bool Paddle::collideDown(QGraphicsEllipseItem *q_ball)
{
    if (q_ball->collidesWithItem(downCollision) && !hasCollided)
    {
        hasCollided = true;
        return true;
    }
    return false;
}

bool Paddle::collideLeft(QGraphicsEllipseItem *q_ball)
{
    if (q_ball->collidesWithItem(leftCollision) && !hasCollided)
    {
        hasCollided = true;
        return true;
    }
    return false;
}

bool Paddle::collideRight(QGraphicsEllipseItem *q_ball)
{
    if (q_ball->collidesWithItem(rightCollision) && !hasCollided)
    {
        hasCollided = true;
        return true;
    }
    return false;
}

bool Paddle::collideHorizontalSide(QGraphicsEllipseItem *q_ball)
{
    return ( collideLeft(q_ball) || collideRight(q_ball) );
}

bool Paddle::collideVerticalSide(QGraphicsEllipseItem *q_ball)
{
    return ( collideUp(q_ball) || collideDown(q_ball) );
}


void Paddle::moveUp(int delta)
{
    velocity = -PADDLE_SPEED;
}

void Paddle::moveDown(int delta)
{
    velocity = PADDLE_SPEED;
}

void Paddle::brake()
{
    velocity = 0;
}

void Paddle::update()
{
    if ( paddle->y() < BOARD_HEIGHT - PADDLE_HEIGTH && paddle->y() > 0 ) paddle->setPos(paddle->x(), paddle->y() + velocity);
    else brake();
    
    leftCollision->setPos(x(), y());
    rightCollision->setPos(x(), y());
    upCollision->setPos(x(), y());
    downCollision->setPos(x(), y());

    hasCollided = false;
}


bool Paddle::collide(QGraphicsEllipseItem *ball, QGraphicsLineItem *collider)
{
    if (ball->collidesWithItem(collider) && !hasCollided)
    {
        hasCollided = true;
        return true;
    }
    return false;
}