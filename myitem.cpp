#include "myitem.h"
#include <QDebug>
#include "hander.h"
#include <QCursor>
MyItem::MyItem()
{
    this->setPixmap(QPixmap(":/bg/pic/dong.jpg"));
    this->setStart(false);
    this->setMouse(false);
    this->setCursor(QCursor(QPixmap(":/bg/pic/chui_up.png")));
}
void MyItem::setPic(QString path)
{
    this->setPixmap(QPixmap(path));
}
void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/bg/pic/chui_down.png")));
    if(this->isStart()){
        if(this->isMouse()){
            hander *hand = hander::getInstance();
            this->setPic(":/bg/pic/beatMouse.jpeg");
            emit hand;
            hand->addScore();
            this->setMouse(false);
        }
    }
}
void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    this->setCursor(QCursor(QPixmap(":/bg/pic/chui_up.png")));
}

void MyItem::setStart(bool start){
    this->start = start;
}
bool MyItem::isStart(){
    return this->start;
}

void MyItem::setMouse(bool mouse)
{
    this->mouse = mouse;
}
bool MyItem::isMouse()
{
    return this->mouse;
}
