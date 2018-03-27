#include "pongscene.h"


PongScene::PongScene(QObject *parent) : QGraphicsScene()
{
    this->setSceneRect(0, 450, 700, -450);
    this->addLine(40, 40, 660, 40, QPen(Qt::green, 5));
    this->addLine(40, 40, 40, 400, QPen(Qt::green, 5));
    this->addLine(40, 400, 660, 400, QPen(Qt::green, 5));
    this->addLine(660, 400, 660, 40, QPen(Qt::green, 5));

    Q_UNUSED(parent);
}

PongScene::~PongScene()
{

}
