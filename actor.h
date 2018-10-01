#ifndef ACTOR_H
#define ACTOR_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include "enemy.h"
#include "bullet.h"

class Actor : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Actor(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *event);
private:
    QMediaPlayer *shootSound;

public slots:
    void spawn();
};

#endif // ACTOR_H
