#ifndef JUGADOR_H
#define JUGADOR_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QKeyEvent>

#include "proyectil.h"

#include <QDebug>

class Jugador: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Jugador(QGraphicsItem * parent = nullptr);
    void keyPressEvent(QKeyEvent * event);
    int getPosX();
private:
    int vel_x;
    int vel_y;

    Proyectil * proyectil;
};

#endif // JUGADOR_H
