#ifndef PLAYER1_H
#define PLAYER1_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class Player1 : public QObject, public QGraphicsItem
{
    friend class Widget;
public:
    explicit Player1(QObject *parent = nullptr);
    ~Player1();
public:
    float getLeftY_coord() const;
    float getLeftX_coord() const;
    int getRacketWidth() const;
    int getRacketHeight() const;
private slots:
    void slotUpdatePosition();
    void simpleSmallNN();
private:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    int racketWidth{10};
    int racketHeight{50};
};

#endif // PLAYER1_H
