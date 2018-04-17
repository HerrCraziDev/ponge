#ifndef DEF_PONGE_BALL
#define DEF_PONGE_BALL

//#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <iostream>

class Ball
{
    public:
    Ball() {};
    Ball(float x, float y, int radius = 20);
    ~Ball();

    float getX() const;
    float getY() const;
    float getVx() const;
    float getVy() const;

    void setPosition(float nx, float ny);
    void setVx(float vx);
    void setVy(float vy);

    void update();

  private:
    float bx, by, vx, vy;
    
};

#endif