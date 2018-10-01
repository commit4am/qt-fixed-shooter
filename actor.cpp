#include "actor.h"

Actor::Actor(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    shootSound = new QMediaPlayer();
    shootSound->setMedia(QUrl("qrc:/sounds/shoot.wav"));

    setPixmap(QPixmap(":/images/player.png"));
}

void Actor::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        if (pos().x() > 0)
            setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right)
        if (pos().x() + 64 < 640)
            setPos(x()+10,y());
    if (event->key() == Qt::Key_Space)
    {
        Bullet *bullet = new Bullet();
        bullet->setPos(x()+28,y());
        scene()->addItem(bullet);

        if (shootSound->state() == QMediaPlayer::PlayingState)
            shootSound->setPosition(0);
        else if (shootSound->state() == QMediaPlayer::StoppedState)
            shootSound->play();
    }
}

void Actor::spawn()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
