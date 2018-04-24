#include "Ponge.hpp"

Ponge::Ponge(QWidget *parent) : QGraphicsScene(parent), ball(BOARD_WIDTH/2 - 10, BOARD_HEIGHT/2 - 10), leftPaddle(this, 1), rightPaddle(this, 2), leftPlayer(1, leftPaddle), rightPlayer(2, rightPaddle)
{
    this->setBackgroundBrush(Qt::NoBrush);

    QGraphicsRectItem *imagebackground = new QGraphicsRectItem(0, 0, BOARD_WIDTH + 40, BOARD_HEIGHT + 40);
    imagebackground->setBrush(Qt::red);
    imagebackground->setPen(Qt::NoPen);
    imagebackground->setZValue(-2);
    imagebackground->setPos(-20,-20);

    QGraphicsRectItem *dirtybackground = new QGraphicsRectItem(-10, -10, BOARD_WIDTH + 20, BOARD_HEIGHT + 20);
    dirtybackground->setBrush(Qt::black);
    dirtybackground->setPen(QPen(Qt::NoPen));
    dirtybackground->setZValue(-1);
    dirtybackground->setOpacity(0.7);

    /*QGraphicsRectItem *rectogle = new QGraphicsRectItem(BOARD_WIDTH - 20,170,10,60);
    rectogle->setBrush(Qt::white);

    QGraphicsRectItem *rectagle = new QGraphicsRectItem(10, 170, 10, 60);
    rectagle->setBrush(Qt::white);*/

    /*QGraphicsEllipseItem *maboule = new QGraphicsEllipseItem(50,50,10,10);
    maboule->setBrush(Qt::white);*/

    i_ball = new QGraphicsEllipseItem(0,0,20,20);
    i_ball->setBrush(Qt::white);
    i_ball->setPos(BOARD_WIDTH/2 - 10, BOARD_HEIGHT/2 - 10);

    lecotegauche = this->addLine( 0, 0, 0, BOARD_HEIGHT,QPen(Qt::white,4, Qt::SolidLine) );
    lecotedroit = this->addLine( BOARD_WIDTH, 0, BOARD_WIDTH, BOARD_HEIGHT, QPen(Qt::white, 4, Qt::SolidLine) );
    lecotehaut = this->addLine( 0, 0, BOARD_WIDTH, 0, QPen(Qt::white, 4, Qt::SolidLine) );
    lecotebas = this->addLine( 0, BOARD_HEIGHT, BOARD_WIDTH, BOARD_HEIGHT, QPen(Qt::white, 4, Qt::SolidLine) );

    this->addLine(BOARD_WIDTH/2, 0, BOARD_WIDTH/2, BOARD_HEIGHT, QPen(Qt::white, 4, Qt::DotLine));

    this->addItem(dirtybackground);
    this->addItem(imagebackground);
    //this->addItem(rectogle);
    //this->addItem(rectagle);
    this->addItem(i_ball);

    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(update()) );
    timer->start(1000/60);

    qDebug() << "Timer attached";

    QImage background = QImage("assets/textures/ponge_menubk.png");

    imagebackground->setBrush(QBrush(background.scaledToHeight(BOARD_HEIGHT+40)));
}

Ponge::~Ponge() {}

void Ponge::update()
{
    //qDebug() << "upd8";

    ball.update();

    leftPaddle.update();
    rightPaddle.update();

    i_ball->setPos(ball.getX(), ball.getY());

    if (i_ball->collidesWithItem(lecotegauche) || 
        i_ball->collidesWithItem(lecotedroit) ||
        leftPaddle.collideHorizontalSide(i_ball) ||
        rightPaddle.collideHorizontalSide(i_ball)
    )
    {
        ball.setVx(-ball.getVx());
    }
    
    if (i_ball->collidesWithItem(lecotehaut) ||
        i_ball->collidesWithItem(lecotebas) ||
        leftPaddle.collideVerticalSide(i_ball) ||
        rightPaddle.collideVerticalSide(i_ball)
    )
    {
        ball.setVy(-ball.getVy());
    }
}

void Ponge::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_I:
            qDebug() << "Down\n";
            rightPaddle.moveUp();
            break;

        case Qt::Key_K:
            qDebug() << "Up\n";
            rightPaddle.moveDown();
            break;

        case Qt::Key_Z:
            qDebug() << "Player 1 : Up\n";
            leftPaddle.moveUp();
            break;

        case Qt::Key_S:
            qDebug() << "Player 1 : Down\n";
            leftPaddle.moveDown();
            break;
    }
}

void Ponge::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_I:
    case Qt::Key_K:
        rightPaddle.brake();
        break;

    case Qt::Key_Z:
    case Qt::Key_S:
        leftPaddle.brake();
        break;
    }
}