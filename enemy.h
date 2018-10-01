#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <stdlib.h>
#include "gameplay.h"

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(QGraphicsItem *parent=0);
public slots:
    void move();
private:
    float moveSpeed;
};

#endif // ENEMY_H
