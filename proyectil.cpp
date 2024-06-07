#include "proyectil.h"

#include <QDebug>


Proyectil::Proyectil(int _vel_x, int _vel_y, int _pos_x0, int _pos_y0) {
    // Dibujar proyectil
    setRect(0, 0, 40, 40);

    this->vel_x = _vel_x;
    this->vel_y = _vel_y;
    this->pos_x0 = _pos_x0;
    this->pos_y0 = _pos_y0;

    qDebug("x0 = ", _pos_x0);
    qDebug("y0 = ", _pos_y0);

    //connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

int Proyectil::calcular_posicion_y(){
    return this->pos_y0 - this->vel_y * this->t + this->gravedad * this->t * this->t;
}

int Proyectil::calcular_posicion_x(){
    return this->pos_x0 + this->vel_x * this->t;
}

void Proyectil::move()
{
    // Mover hacia arriba
    setPos(this->calcular_posicion_x(), this->calcular_posicion_y());
    this->t += 0.05;
    if(pos().y() > scene()->height()) {
        scene()->removeItem(this);
        delete this;
        qDebug("Proyectil eliminado");
    }
}
