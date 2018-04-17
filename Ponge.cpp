#include "Ponge.hpp"

Ponge::Ponge(QWidget *parent) : QGraphicsScene(parent), ball(50,50), leftPaddle(this, 1), rightPaddle(this, 2), leftPlayer(1, leftPaddle), rightPlayer(2, rightPaddle)
{
    this->setBackgroundBrush(Qt::black);

    QGraphicsRectItem *dirtybackground = new QGraphicsRectItem(-10, -10, BOARD_WIDTH + 20, BOARD_HEIGHT + 20);
    dirtybackground->setBrush(Qt::NoBrush);
    dirtybackground->setPen(Qt::NoPen);

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
    //this->addItem(rectogle);
    //this->addItem(rectagle);
    this->addItem(i_ball);

    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(update()) );
    timer->start(1000/60);

    qDebug() << "Timer attached";



}

Ponge::~Ponge() {}

void Ponge::update()
{
    //qDebug() << "upd8";
    

    if (i_ball->collidesWithItem(lecotegauche) || i_ball->collidesWithItem(lecotedroit))
    {
        ball.setVx(-ball.getVx());
    }

    if ( (i_ball->collidesWithItem(lecotehaut)) || (i_ball->collidesWithItem(lecotebas)) )
    {
        ball.setVy(-ball.getVy());
    }

    ball.update();

    i_ball->setPos(ball.getX(), ball.getY());
    //this->setBackgroundBrush( QBrush( QColor::fromHsv( (rand() % 255), 255, 200 ) ) );

}

void Ponge::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Down:
            qDebug() << "Down\n";
            break;

        case Qt::Key_Up:
            qDebug() << "Up\n";
            break;

        case Qt::Key_Z:
            qDebug() << "Player 1 : Up\n";
            break;

        case Qt::Key_S:
            qDebug() << "Player 1 : Down\n";
            break;
    }
}