#include "proyectil.h"


Proyectil::Proyectil() {
    // Dibujar proyectil
    setRect(0, 0, 10, 10);

    //connect


    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Proyectil::move()
{
    // Mover hacia arriba
    setPos(x(), y() - 10);
}
