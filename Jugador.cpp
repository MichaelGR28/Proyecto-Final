#include "Jugador.h"

void Jugador::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        setPos(x() - 10, y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x() + 10, y());
    }
    else if (event->key() == Qt::Key_Space){
        Proyectil * proyectil = new Proyectil(300,300,x(),y());
        proyectil->setPos(x(),y());
        qDebug() << "Proyectil creado";
        scene()->addItem(proyectil);
    }
}

