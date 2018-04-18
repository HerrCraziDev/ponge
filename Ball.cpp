#include "Ball.hpp"

Ball::Ball(float x, float y, int radius) : bx(x), by(y)
{       
    srand(time(NULL));
    //std::cout << rand();

    vx = (rand()%1000)/100 - 1;
    vy = (rand()%1000)/100 - 1;

    std::cout << "\nvx : " << vx << ", vy : " << vy << "\nx : " << bx << ", y : " << y << "\n-------------------------\n";
}

Ball::~Ball()
{

}

float Ball::getX() const
{
    return bx;
}

float Ball::getY() const
{
    return by;
}

float Ball::getVx() const
{
    return vx;
}

float Ball::getVy() const
{
    return vy;
}

void Ball::setPosition(float nx, float ny)
{
    bx = nx;
    by = ny;
}

void Ball::setVx(float nvx)
{
    vx = nvx;
}

void Ball::setVy(float nvy)
{
    vy = nvy;
}

void Ball::update()
{
    bx += vx;
    by += vy;

    std::cout << "\r\tx: " << bx << ", y: " << by << "\t ; vx : " << vx << ", vy : " << vy << "        \r";

    std::cout.flush();
}