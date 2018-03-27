#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(730, 480);

    scene = new PongScene();
    ui->graphicsView->setScene(scene);

    QTimer *movingTimer = new QTimer();
    connect(movingTimer, &QTimer::timeout, this, &Widget::slotBallMoving);
    movingTimer->start(4);
    player1 = new Player1();
    player2 = new Player2();
    ball = new Ball();
    scene->addItem(player1);
    scene->addItem(player2);
    scene->addItem(ball);
    racketHeight = player1->getRacketHeight();
    racketWidth = player1->getRacketWidth();
}


Widget::~Widget()
{
    delete ui;
}

void Widget::slotBallMoving()
{
    ball->setX(ball->x() + (ball_speed * ball->getXdir()));
    ball->setY(ball->y() + (ball_speed * ball->getYdir()));

    if( ball->y() >= (25 + sceneWidth) ) {                   //hit by bottom wall
        ball->setYdir( -(fabs( ball->getYdir()) ) );
    }

    if( ball->y() <=  (25 ) ) {                             //hit by top wall
        ball->setYdir( (fabs( ball->getYdir()) ) );
    }

    if( ball->x() >= (60 + sceneHeight) ) {    //hit by right wall
        ui->scorePlayer1->display(++scoreP1);
        ball->setY( ( sceneWidth + 70 ) / 2);
        ball->setX( ( sceneHeight + 70 ) / 2);
        ball->setXdir( -(fabs( ball->getXdir()) ) );
    }

    if( ball->x() <= ( -10 ) ) {                // hit by left wall
        ui->scorePlayer2->display(++scoreP2);
        ball->setY( ( sceneWidth + 70 ) / 2);
        ball->setX( ( sceneHeight + 70 ) / 2);
        ball->setXdir( (fabs( ball->getXdir()) ) );
    }

    if( ball->x() <= player1->getLeftX_coord() + player1->getRacketWidth() &&
        ball->x()  > player1->getLeftX_coord() &&
        ball->y() <= player1->getLeftY_coord() + player1->getRacketHeight() &&
        ball->y() + 15 >= player1->getLeftY_coord()) {
        float placeHited = ( (ball->y() - player1->getLeftY_coord()) / player1->racketHeight ) - 0.5;
        ball->setXdir( fabs( ball->getXdir() ) );
        ball->setYdir( placeHited );


    }

    if( ball->x() >= player2->getLeftX_coord()  &&
        ball->x()  < player2->getLeftX_coord() + player2->getRacketWidth() &&
        ball->y() <= player2->getLeftY_coord() + player2->getRacketHeight() &&
        ball->y() + 15 >= player2->getLeftY_coord()) {
        float placeHited = ( (ball->y() - player2->getLeftY_coord()) / player2->racketHeight ) - 0.5;
        ball->setXdir( -fabs( ball->getXdir() ) );
        ball->setYdir( placeHited );


    }

    scene->update();
}
