#include "gameplay.h"

GamePlay::GamePlay(QWidget *parent)
{
    gameOver = false;
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,640,480);
    setBackgroundBrush(QBrush(QImage(":/images/background.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    Actor *actor = new Actor();
    actor->setPos(320, 380);
    actor->setFlag(QGraphicsItem::ItemIsFocusable);
    actor->setFocus();

    scene->addItem(actor);
    setFixedSize(640,480);

    score = new Score();
    scene->addItem(score);

    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),actor,SLOT(spawn()));
    timer->start(2000);

    show();
}

void GamePlay::displayGameOver(int highScore)
{
    for (size_t i = 0, n=scene->items().size();i<n;i++)
        scene->items()[i]->setEnabled(false);
    timer->stop();
    QGraphicsRectItem *panel = new QGraphicsRectItem(160,120,300,320);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    panel->setBrush(brush);
    panel->setOpacity(0.65);
    scene->addItem(panel);
    QGraphicsTextItem *gameOverText = new QGraphicsTextItem(QString("GAME OVER!\nYour score:")+QString::number(highScore));
    gameOverText->setDefaultTextColor(Qt::magenta);
    gameOverText->setFont(QFont("Pixelette",20));
    gameOverText->setPos(185,160);
    scene->addItem(gameOverText);
}
