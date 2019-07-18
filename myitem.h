#ifndef MYITEM_H
#define MYITEM_H
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QGraphicsSceneMouseEvent>

class MyItem : public QGraphicsPixmapItem
{
public:
    MyItem();
    void setPic(QString);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    void setMouse(bool mouse);
    bool isMouse();
    bool isStart();
    void setStart(bool start);
private:
    bool mouse;
    bool start;
};


#endif // MYITEM_H
