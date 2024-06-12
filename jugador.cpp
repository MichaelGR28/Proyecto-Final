#include "jugador.h"
#include "game.h"

extern Game *game;

Jugador::Jugador(QGraphicsItem *parent): QGraphicsRectItem(parent) {
    vel_x = 0;
    vel_y = 0;
    gravedad = 200;
    fila = 64*7;
    columna = 0;

    alto = 64;
    ancho = 64;

    pixmap = new QPixmap(":/imagenes/Movimiento_Jugador.png");

    timer = new QTimer(this);
    timerSprite = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(colisiones()));
    connect(timerSprite,SIGNAL(timeout()),this,SLOT(actualizarSprite()));

    timerSprite->start(150);
    timer->start(10);
}

void Jugador::keyPressEvent(QKeyEvent *event) {

    // Movimiento jugador
    if (event->key() == Qt::Key_Left) {
        aceleracion_x = -200;
        if (!event->isAutoRepeat()){
            pos_x0 = pos().x();
            pos_y0 = pos().y();
            vel_x = 0;
            vel_y = vel_y + gravedad*tiempo;
            fila = 64*9;
            tiempo = 0;
        }
    }
    if (event->key() == Qt::Key_Right) {
        aceleracion_x = 200;
        if (!event->isAutoRepeat()){
            pos_x0 = pos().x();
            pos_y0 = pos().y();
            vel_x = 0;
            vel_y = vel_y + gravedad*tiempo;
            fila = 64*11;
            tiempo = 0;
        }
    }
    // Salto del jugador
    if (!event->isAutoRepeat()){
        if (event->key() == Qt::Key_Up) {
            vel_y = -300;
            gravedad = 200;
            pos_x0 = pos().x();
            pos_y0 = pos().y();
            tiempo = 0;
        }
    }

    // Disparos jugador
    if (event->key() == Qt::Key_A) {
        proyectil = new Proyectil(-300,-200);
        proyectil->setPos(pos().x() + this->rect().width()/2-proyectil->rect().width()/2, pos().y());
        proyectil->posicionInicial();
        scene()->addItem(proyectil);
    }
    if(event->key() == Qt::Key_D){
        proyectil = new Proyectil(300,-200);
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
            vel_x = vel_xa;
            vel_y = vel_y + gravedad*tiempo;
            aceleracion_x = 200;
            fila = 64*5;
            tiempo = 0;
        } else if(event->key() == Qt::Key_Right && aceleracion_x != 0){
            pos_x0 = pos().x();
            pos_y0 = pos().y();
            vel_x = vel_x + aceleracion_x*tiempo;
            vel_y = vel_y + gravedad*tiempo;
            aceleracion_x = -200;
            fila = 64*7;
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

QRectF Jugador::boundingRect() const
{
    return QRectF(0,0,ancho,alto);
}

void Jugador::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,*pixmap,columna,fila,ancho,alto);
}

void Jugador::colisiones()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Muro)){

            qDebug() << "Colisiono";

            // Obtener los bordes del jugador y del muro
            QRectF jugadorRect = this->boundingRect();

            // Obtener las posiciones actuales
            QPointF jugadorPos = this->pos();
            QPointF muroPos = colliding_items[i]->pos();

            // Colision por arriba
            if(jugadorPos.y() < muroPos.y() && (jugadorPos.y() + jugadorRect.height()) >= muroPos.y()) {
                setPos(jugadorPos.x(), jugadorPos.y() - (jugadorPos.y() + jugadorRect.height() - muroPos.y() + 1));
                gravedad = 0;
                vel_x = vel_x + gravedad*tiempo;
                vel_y = 0;
                tiempo = 0;
                pos_y0 = muroPos.y() - jugadorRect.height();
                pos_x0 = jugadorPos.x();
            }

            return;
        }

        // Colision puerta
        if (typeid(*(colliding_items[i])) == typeid(Puerta)) {
            QPointF posPuerta = colliding_items[i]->pos();

            setPos(posPuerta.x() - this->rect().width() - 1, pos().y());
            vel_x = 0;
            aceleracion_x = 0;
            vel_y = vel_y + gravedad*tiempo;
            tiempo = 0;
            pos_y0 = pos().y();
            pos_x0 = posPuerta.x() - this->rect().width() - 1;

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
        tiempo = 0;
    } else if (vel_xa >= 300 && (aceleracion_x >= 1 || aceleracion_x <= -1)) {
        pos_x0 = pos().x();
        pos_y0 = pos().y();
        vel_x = 300;
        vel_y = vel_y + gravedad*tiempo;
        tiempo = 0;
        aceleracion_x = 0;

    } else if (vel_xa <= -300 && (aceleracion_x >= 1 || aceleracion_x <= -1)) {
        pos_x0 = pos().x();
        pos_y0 = pos().y();
        vel_x = -300;
        vel_y = vel_y + gravedad*tiempo;
        tiempo = 0;
        aceleracion_x = 0;
    }

    setPos(pos_x0 + vel_x*tiempo + aceleracion_x*tiempo*tiempo/2,pos_y0 + vel_y*tiempo + gravedad*tiempo*tiempo/2);

}

void Jugador::actualizarSprite()
{
    columna += 64;
    if(columna == 64*7) {
        columna = 0;
    }
    this->update(0,0,ancho,alto);
}
