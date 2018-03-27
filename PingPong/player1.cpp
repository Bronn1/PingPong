#include "player1.h"

#include <QDebug>
#include "windows.h"


Player1::Player1(QObject *parent) : QObject(parent), QGraphicsItem()
{
    QTimer *checkMoving = new QTimer();
    setPos(20, 200);

    connect(checkMoving, &QTimer::timeout, this, &Player1::slotUpdatePosition);
    checkMoving->start(7);
}

Player1::~Player1()
{

}

float Player1::getLeftY_coord() const
{
    return this->y();
}

float Player1::getLeftX_coord() const
{
    return this->x();
}

int Player1::getRacketWidth() const
{
    return racketWidth;
}

int Player1::getRacketHeight() const
{
    return racketHeight;
}

void Player1::slotUpdatePosition()
{
    if(GetAsyncKeyState('S')) { this->setY( this->y() + 2); } // движение игрока
    if(GetAsyncKeyState('W')) { this->setY( this->y() - 2); }

    if(this->y() >= 420) { this->setY(420); } // ограничения не выхода за зону
    if(this->y() <= 20) { this->setY(20); }
}

void Player1::simpleSmallNN()
{
    QVector<QVector<double>> weights;

   // for(auto)
}

QRectF Player1::boundingRect() const
{
    return QRectF(QRect(0, 0, racketWidth, racketHeight)); //0, 20, 10, 50
}

void Player1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::red);
    painter->setBrush(Qt::black);
    painter->drawRect(0, 0, racketWidth, racketHeight);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
