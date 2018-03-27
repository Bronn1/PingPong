#ifndef PONGSCENE_H
#define PONGSCENE_H

#include <QObject>
#include <QGraphicsScene>

class PongScene : public QGraphicsScene
{
public:
    explicit PongScene(QObject *parent = 0);
    ~PongScene();
};

#endif // PONGSCENE_H
