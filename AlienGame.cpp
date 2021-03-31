#include <QApplication>
#include <QFont>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include <QTimer>
#include <QLabel>
#include <QString>
#include "AlienGame.h"
#include "SpaceShipPlayer.h"
#include "AlienEnemy.h"
#include <QMediaPlayer>
#include <QPicture>
#include <QBrush>
#include <QDebug>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

extern QTimer * AlienTimer;
extern QMediaPlayer * AlienMusic;

AlienGame::AlienGame(QWidget * parent){

//create a scene
scene = new QGraphicsScene();
scene->setSceneRect(0,0,805,600);
setBackgroundBrush(QBrush(QImage(":/images/Space1.jpg")));
//assign the scene
setScene(scene);
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //these are so that you dont scroll off the screen when you shoot
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setFixedSize(805,600);


//create a player to put into the scene
Player* player = new Player();
player->setPos(400,550);
//make the item focusable
player->setFlag(QGraphicsItem::ItemIsFocusable);
player->setFocus();
//add item to the scene
scene->addItem(player);

//create a score
score = new Score();
scene->addItem(score);
//create health
health = new Health();
health->setPos(health->x()+5,health->y()+25);
scene->addItem(health);

//spawn enemies
//I wanna add two types of enemies. I will make it a random chance to get harder enemies 1/3 inside of "spawn"
AlienTimer =  new QTimer();
QObject::connect(AlienTimer, SIGNAL(timeout()),player,SLOT(spawn()));

AlienTimer->start(850);  //the rate (in ms) for how fast the monsters will come out


//play background music
AlienMusic = new QMediaPlayer();
AlienMusic->setMedia(QUrl("qrc:/sounds/Lofi.mp3"));
AlienMusic->play();




}
