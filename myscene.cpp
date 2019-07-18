#include "myscene.h"
#include <QGraphicsPixmapItem>
#include <stdlib.h>
MyScene::MyScene(QObject *parent) : QGraphicsScene(parent)
{
    this ->ptimer = new QTimer;
    int i;
    for(i=0;i<16;i++){
        this -> items[i] = new MyItem;
        this -> items[i] ->setPos(i/4*this->items[i]->boundingRect().width(),
                                  i%4*this->items[i]->boundingRect().height());
        this->addItem(this->items[i]);
        this->items[i]->setMouse(false);
    }
    connect(this->ptimer,SIGNAL(timeout()),this,SLOT(showMouse()));


}
void MyScene::showMouse()
{
    for(int i=0;i<16;i++){
        this->items[i]->setPic(":/bg/pic/dong.jpg");
        this->items[i]->setMouse(false);
    }
    int count = rand()%3+1;
    for(int i=0;i<count;i++){
        int index = rand()%16;
        this->items[index]->setPic(":/bg/pic/mouse.jpg");
        this->items[index]->setMouse(true);
    }
}
void MyScene::startGame(){
    this->ptimer->start(1000);
    for(int i =0;i<16;i++){
        this->items[i] ->setStart(true);
    }
}
void MyScene::pauseGame(){
    this->ptimer->stop();
    for(int i =0;i<16;i++){
        this->items[i] ->setStart(false);
    }
}
void MyScene::stopGame(){
    for(int i=0;i<16;i++){
        this->items[i]->setPic(":/bg/pic/dong.jpg");
        this->items[i]->setMouse(false);
        this->items[i]->setStart(false);
    }
    this->ptimer->stop();

}
