#ifndef JUGADOR_H
#define JUGADOR_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

#include "proyectil.h"

#include <QDebug>

class Jugador: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Jugador(QGraphicsItem * parent = nullptr);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);
    int getPosX();
    void posicionInicial();
    QTimer * timer;
public slots:
    void colisiones();
private:
    float pos_x0;
    float pos_y0;
    float vel_x = 0;
    float vel_y = 0;
    float vel_xa = 0;
    int aceleracion_x = 0;
    float tiempo = 0;
    float gravedad;

    Proyectil * proyectil;
};

#endif // JUGADOR_H
