#ifndef PLAYER2_H
#define PLAYER2_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>


class Player2 : public QObject, public QGraphicsItem
{
    friend class Widget;
public:
    explicit Player2(QObject *parent = nullptr);
    ~Player2();
public:
    float getLeftY_coord() const;
    float getLeftX_coord() const;
    int getRacketWidth() const;
    int getRacketHeight() const;
private slots:
    void slotUpdatePosition();
private:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    int racketWidth{10};
    int racketHeight{50};
};

#endif // PLAYER2_H
