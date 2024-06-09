#include "jugador.h"

Jugador::Jugador(QGraphicsItem *parent): QGraphicsRectItem(parent) {
    vel_x = 0;
    vel_y = 0;
}

void Jugador::keyPressEvent(QKeyEvent *event) {

    //qDebug() << "pos_x0: " << pos_x0;
    //qDebug() << "pos_y0: " << pos_y0;
    switch (event->key()) {
    case Qt::Key_Left:
        setPos(pos().x() - 10,pos().y());
        break;

    case Qt::Key_Right:
        setPos(pos().x() + 10, pos().y());
        break;

    case Qt::Key_A:
        proyectil = new Proyectil(-300,-300);
        proyectil->setPos(pos().x() + this->rect().width()/2-proyectil->rect().width()/2, pos().y());
        proyectil->posicionInicial();
        scene()->addItem(proyectil);
        break;

    case Qt::Key_D:
        proyectil = new Proyectil(300,-300);
        proyectil->setPos(pos().x() + this->rect().width()/2-proyectil->rect().width()/2, pos().y());
        proyectil->posicionInicial();
        scene()->addItem(proyectil);
        break;

    default:
        break;
    }
}

int Jugador::getPosX()
{
    return pos().x();
}
