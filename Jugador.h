#ifndef JUGADOR_H
#define JUGADOR_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "proyectil.h"
#include <QDebug>

// Clase Jugador
class Jugador: public QGraphicsRectItem {
public:
    void keyPressEvent(QKeyEvent * event);
};

#endif // JUGADOR_H
