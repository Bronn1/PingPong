#include <windows.h>

#include "player2.h"

Player2::Player2(QObject *parent) : QObject(parent), QGraphicsItem()
{
    QTimer *checkMoving = new QTimer();
    setPos(670, 200);

    connect(checkMoving, &QTimer::timeout, this, &Player2::slotUpdatePosition);
    checkMoving->start(6);
}

Player2::~Player2()
{

}

float Player2::getLeftY_coord() const
{
    return this->y();
}

float Player2::getLeftX_coord() const
{
    return this->x();
}

int Player2::getRacketWidth() const
{
    return racketWidth;
}

int Player2::getRacketHeight() const
{
    return racketHeight;
}

void Player2::slotUpdatePosition()
{
    if(GetAsyncKeyState(VK_DOWN)) { this->setY( this->y() + 1); } // движение игрока
    if(GetAsyncKeyState(VK_UP)) { this->setY( this->y() - 1); }

    if(this->y() >= 420) { this->setY(420); } // ограничения не выхода за зону
    if(this->y() <= 20) { this->setY(20); }

}

QRectF Player2::boundingRect() const
{
    return QRectF(QRect(0, 0, 10, 50));
}

void Player2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::red);
    painter->setBrush(Qt::black);
    painter->drawRect(0, 0, 10, 50);

    Q_UNUSED(option);
    Q_UNUSED(widget);

}
