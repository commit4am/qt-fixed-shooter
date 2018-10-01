#include "enemy.h"

extern GamePlay *gamePlay;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    moveSpeed=0.5;
    if (gamePlay->score->score>10)
        moveSpeed=0.5*(gamePlay->score->score/10);
    int random_number = rand() % 500;
    setPos(random_number,0);
    setPixmap(QPixmap(":/images/enemy.png"));

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(30);
}

void Enemy::move()
{
    setPos(x(),y()+moveSpeed);
    if (pos().y() > 380)
       if (!gamePlay->gameOver)
       {
            gamePlay->gameOver = true;
            gamePlay->displayGameOver(gamePlay->score->score);
       }
}
