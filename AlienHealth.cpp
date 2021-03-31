#include "AlienHealth.h"
#include "QGraphicsTextItem"
#include <QFont>
#include <QDebug>
#include <QLabel>
#include <QGraphicsScene>
#include <QTimer>
#include <QMediaPlayer>
#include <AlienGame.h>

extern QTimer * AlienTimer;
extern QMediaPlayer * AlienMusic;
extern AlienGame * alienGame;

Health::Health(QGraphicsPixmapItem *parent) : QGraphicsPixmapItem(parent){
    //initialize the variables
    health = 3;

    //draw heart
   setPixmap(QPixmap(":/images/Zelda-Health3.png"));



}

void Health::decrease()
{
    health--;
    //gotta update the picture inside of the function increase
    if(health == 2)
    {
        setPixmap(QPixmap(":/images/Zelda-Health2.png"));
    }
    if(health == 1)
    {
        setPixmap(QPixmap(":/images/Zelda-Health.png"));

    }
    if(health <= 0)
    {
        this->hide();
        AlienTimer->stop();
        AlienMusic->stop();
        alienGame->hide();
        alienGame->close();
    }
    //this is how you will end the game

}

int Health::getHealth()
{
    return health;
}
