#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

#include "enemigo.h"

#include <QDebug>

class Proyectil: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Proyectil(int _velX, int _velY, QGraphicsItem * parent = nullptr);
    void posicionInicial();

    QTimer * timer;
public slots:
    void movimiento();
private:
    int velX;
    int velY;
    int posX0;
    int posY0;
    float gravedad = 300;
    float tiempo = 0;
};

#endif // PROYECTIL_H
