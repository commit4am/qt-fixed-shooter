#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <QImage>
#include "actor.h"
#include "score.h"

class GamePlay: public QGraphicsView
{
public:
    GamePlay(QWidget *parent=0);

    QGraphicsScene *scene;
    Score *score;
    bool gameOver;
    QTimer *timer;
    void displayGameOver(int highScore);
};

#endif // GAMEPLAY_H
