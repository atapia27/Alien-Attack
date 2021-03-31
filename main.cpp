#include <QApplication>
#include <AlienGame.h>

AlienGame* alienGame;
QTimer * AlienTimer;
QMediaPlayer * AlienMusic;

int main(int argc, char *argv[]){
    QApplication a (argc, argv);

    alienGame = new AlienGame();
    alienGame->show();

    return a.exec();

}
