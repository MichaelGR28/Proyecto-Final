#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>

class Proyectil: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Proyectil();
public slots:
    void move();
};

#endif // PROYECTIL_H
