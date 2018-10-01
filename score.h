#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent=0);
    void increase();
    int getScore();
    int score;
private:
    QMediaPlayer *pointSound, *achievementSound;
};

#endif // SCORE_H
