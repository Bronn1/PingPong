

#include "ball.h"

Ball::Ball(QObject *parent)
{

    setPos(350, 200);
}

Ball::~Ball()
{

}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::red);
    painter->setBrush(Qt::black);
    painter->drawEllipse(QPoint(8, 8), ball_size, ball_size);
}

void Ball::setXdir(float dir)
{
    x_dir = dir;
}

void Ball::setYdir(float dir)
{
    y_dir = dir;
}

float Ball::getXdir()
{
    return x_dir;
}

float Ball::getYdir()
{
    return y_dir;
}
