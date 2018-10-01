#include <QApplication>
#include "gameplay.h"

GamePlay *gamePlay;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    gamePlay = new GamePlay();
    gamePlay->show();

    return a.exec();
}
