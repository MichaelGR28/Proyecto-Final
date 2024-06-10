#include "jugador.h"
#include "game.h"

extern Game *game;

Jugador::Jugador(QGraphicsItem *parent): QGraphicsRectItem(parent) {
    vel_x = 0;
    vel_y = 0;
    gravedad = 200;

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(colisiones()));

    timer->start(10);
}

void Jugador::keyPressEvent(QKeyEvent *event) {

    // Movimiento jugador
    if (event->key() == Qt::Key_Left) {
        aceleracion_x = -200;
        if (!event->isAutoRepeat()){
            pos_x0 = pos().x();
            pos_y0 = pos().y();
            gravedad = 200;
            tiempo = 0;
            vel_x = 0;
        }
    }
    if (event->key() == Qt::Key_Right) {
        aceleracion_x = 200;
        if (!event->isAutoRepeat()){
            pos_x0 = pos().x();
            pos_y0 = pos().y();
            gravedad = 200;
            tiempo = 0;
            vel_x = 0;
        }
    }
    // Salto del juegador
    if (!event->isAutoRepeat()){
        if (event->key() == Qt::Key_Up) {
            vel_y = -300;
            gravedad = 200;
            pos_x0 = pos().x();
            pos_y0 = pos().y();
            tiempo = 0;
            qDebug() << "Se realizo un salto";
        }
    }

    // Disparos jugador
    if (event->key() == Qt::Key_A) {
        proyectil = new Proyectil(-300,-300);
        proyectil->setPos(pos().x() + this->rect().width()/2-proyectil->rect().width()/2, pos().y());
        proyectil->posicionInicial();
        scene()->addItem(proyectil);
    }
    if(event->key() == Qt::Key_D){
        proyectil = new Proyectil(300,-300);
        proyectil->setPos(pos().x() + this->rect().width()/2-proyectil->rect().width()/2, pos().y());
        proyectil->posicionInicial();
        scene()->addItem(proyectil);
    }


}

void Jugador::keyReleaseEvent(QKeyEvent *event)
{
    // Cuando se deja de presionar una tecla
    if (!event->isAutoRepeat()){
        if (event->key() == Qt::Key_Left) {
            pos_x0 = pos().x();
            pos_y0 = pos().y();
            gravedad = 200;
            vel_x = vel_xa;
            vel_y = vel_y + gravedad*tiempo;
            aceleracion_x = 200;
            tiempo = 0;
        } else if(event->key() == Qt::Key_Right){
            pos_x0 = pos().x();
            pos_y0 = pos().y();
            gravedad = 200;
            vel_x = vel_x + aceleracion_x*tiempo;
            vel_y = vel_y + gravedad*tiempo;
            aceleracion_x = -200;
            tiempo = 0;
        }
    }
}

int Jugador::getPosX()
{
    return pos().x();
}

void Jugador::posicionInicial()
{
    pos_x0 = pos().x();
    pos_y0 = pos().y();
}

void Jugador::colisiones()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Muro)){
            //qDebug() << "El jugador colisiono con un muro";

            // Obtener los bordes del jugador y del muro
            QRectF jugadorRect = this->boundingRect();
            QRectF muroRect = colliding_items[i]->boundingRect();

            // Obtener las posiciones actuales
            QPointF jugadorPos = this->pos();
            QPointF muroPos = colliding_items[i]->pos();

            // qDebug() << "jugadorAncho: " << jugadorRect.width();
            // qDebug() << "jugadorAlto: " << jugadorRect.height();
            // qDebug() << "jugadorPosX: " << jugadorPos.x();
            // qDebug() << "jugadorPosY: " << jugadorPos.y();

            // qDebug() << "muroAncho: " << muroRect.width();
            // qDebug() << "muroAlto: " << muroRect.height();
            // qDebug() << "muroPosX: " << muroPos.x();
            // qDebug() << "muroPosY: " << muroPos.y();

            // Colision por arriba
            if(jugadorPos.y() < muroPos.y() && (jugadorPos.y() + jugadorRect.height()) >= muroPos.y()) {
                setPos(jugadorPos.x(), jugadorPos.y() - (jugadorPos.y() + jugadorRect.height() - muroPos.y() + 1));
                gravedad = 0;
                vel_y = 0;
                pos_y0 = jugadorPos.y() - (jugadorPos.y() + jugadorRect.height() - muroPos.y());
            }
            // Colision por abajo

            // Colision por la izquierda
            if(jugadorPos.x() < muroPos.x() && (jugadorPos.x() + jugadorRect.width()) >= muroPos.x()) {
                setPos(jugadorPos.x() - (jugadorPos.x() + jugadorRect.width() - muroPos.x() + 1), jugadorPos.y());
                vel_x = 0;
                aceleracion_x = 0;
                tiempo = 0;
                pos_x0 = jugadorPos.x() - (jugadorPos.x() + jugadorRect.width() - muroPos.x() + 1);
            }
            // Colision por la derecha

            return;
        }
    }

    tiempo += 0.01;
    vel_xa = vel_x + aceleracion_x*tiempo;

    if (vel_xa <= 10 && vel_xa >= -10 && vel_x != 0){
        aceleracion_x = 0;
        pos_x0 = pos().x();
        pos_y0 = pos().y();
        vel_x = 0;
        vel_y = vel_y + gravedad*tiempo;
        gravedad = 200;
        tiempo = 0;
    } else if (vel_xa >= 200 && aceleracion_x <= 0.0001 && aceleracion_x >= -0.0001) {
        pos_x0 = pos().x();
        tiempo = 0;
        aceleracion_x = 0;
        vel_x = 200;
    } else if (vel_xa <= -200 && aceleracion_x <= 0.0001 && aceleracion_x >= -0.0001) {
        pos_x0 = pos().x();
        tiempo = 0;
        aceleracion_x = 0;
        vel_x = -200;
    }

    setPos(pos_x0 + vel_x*tiempo + aceleracion_x*tiempo*tiempo/2,pos_y0 + vel_y*tiempo + gravedad*tiempo*tiempo/2);

}
