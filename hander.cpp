#include "hander.h"

hander::hander(QObject *parent) : QObject(parent)
{

}
hander * hander::hand = new hander;
hander * hander::getInstance(){
    return hand;
}
void hander::addScore(){
    emit beatMouse();
}
