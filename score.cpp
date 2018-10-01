#include "score.h"

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor(Qt::magenta);
    setFont(QFont("Pixelette",18));

    pointSound = new QMediaPlayer();
    pointSound->setMedia(QUrl("qrc:/sounds/point.wav"));
    achievementSound = new QMediaPlayer();
    achievementSound->setMedia(QUrl("qrc:/sounds/achievement.wav"));
}


void Score::increase()
{
    score++;
    setPlainText(QString("Score: ")+QString::number(score));
    if (pointSound->state() == QMediaPlayer::PlayingState)
        pointSound->setPosition(0);
    else if (pointSound->state() == QMediaPlayer::StoppedState)
        pointSound->play();
    if (score%10==0)
        achievementSound->play();
}

int Score::getScore()
{
    return score;
}
