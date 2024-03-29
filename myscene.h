#ifndef MYSCENE_H
#define MYSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include "myitem.h"
#include <QTimer>

class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyScene(QObject *parent = nullptr);

signals:

public slots:
    void showMouse();
    void startGame();
    void pauseGame();
    void stopGame();

private:
    MyItem *items[16];
    QTimer *ptimer;
};

#endif // MYSCENE_H
