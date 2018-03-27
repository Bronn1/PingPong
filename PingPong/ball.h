#ifndef BALL_H
#define BALL_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QPainter>

class Ball : public QObject, public QGraphicsEllipseItem
{
    friend class Widget;
public:
    explicit Ball(QObject *parent = nullptr);
    ~Ball();
    float getXdir();
    float getYdir();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setXdir(float dir);
    void setYdir(float dir);
private:
    float x_dir{1}; //direction coordinate
    float y_dir{1};
    int ball_size{15};
    int ball_speed{3};
};

#endif // BALL_H
