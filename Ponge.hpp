#ifndef DEF_PONGE_PONGE
#define DEF_PONGE_PONGE

//#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>

#include "Ball.hpp"
//#include "Paddle.hpp"
#include "Player.hpp"
#include "constants.hpp"

class Ponge : public QGraphicsScene
{
    Q_OBJECT

public:
    Ponge(QWidget *parent = 0);
    ~Ponge();

    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);

  public slots: 
    void update();


private:
    Ball ball;

    Player leftPlayer;
    Player rightPlayer;

    Paddle leftPaddle;
    Paddle rightPaddle;

    QGraphicsEllipseItem *i_ball;
    
    QGraphicsLineItem *lecotegauche;
    QGraphicsLineItem *lecotedroit;
    QGraphicsLineItem *lecotehaut;
    QGraphicsLineItem *lecotebas;

    QTimer *timer;
};

#endif