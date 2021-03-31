#include "SpaceShipScore.h"
#include "QGraphicsTextItem"
#include <QFont>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent){
    //initialize the variables
    score = 0;

    //draw text
    setPlainText(QString("SCORE : ") + QString::number(score));

    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 12));
}

void Score::increase()
{
    score++;
    //gotta update the text inside of the function increase
    setPlainText(QString("SCORE : ") + QString::number(score));
}

int Score::getScore()
{
    return score;
}
