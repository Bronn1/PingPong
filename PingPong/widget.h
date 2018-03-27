#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "pongscene.h"
#include "player1.h"
#include "player2.h"
#include "ball.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    friend class Ball;
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private slots:
    void slotBallMoving();

private:
    Ui::Widget *ui;
    PongScene *scene;
    Player1 *player1;
    Player2 *player2;
    Ball *ball;

    int scoreP1{0};
    int scoreP2{0};
    int sceneHeight{620};
    int sceneWidth{360};
    int racketHeight;
    int racketWidth;
    double ball_speed{1};
};

#endif // WIDGET_H
