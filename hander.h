#ifndef HANDER_H
#define HANDER_H

#include <QObject>

class hander : public QObject
{
    Q_OBJECT
private:
    explicit hander(QObject *parent = nullptr);

signals:
    void beatMouse();
public slots:
public:
    static hander * getInstance();
    void addScore();
private:
    static hander *hand;
};

#endif // HANDER_H
