#ifndef DEF_PONGE_PLAYER
#define DEF_PONGE_PLAYER

/*#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>*/
#include "Paddle.hpp"

class Player
{
    public:
    Player(int playerID, Paddle &paddle);
    ~Player() {}

    void up(double speed = 1);
    void down(double speed = 1);

    void setScore(int nscore);
    int getScore() const;

    private:
    int score;
    int pID;
    Paddle raquette;
   // Paddle *paddle;
    
};

#endif