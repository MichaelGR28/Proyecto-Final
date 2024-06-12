#include "enemigo.h"
#include "game.h"
#include "jugador.h"

extern Game * game;

Enemigo::Enemigo(QGraphicsItem *parent): QObject(), QGraphicsRectItem() {
    int random_number = rand() % 450;
    setPos(game->scene->width() - 100,random_number);

    setRect(0,0,100,100);

    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(movimiento()));

    timer->start(50);

}

void Enemigo::movimiento()
{
    if(game->jugador->collidesWithItem(this)){
        game->vida->quitarVida();
        scene()->removeItem(this);
        delete this;
        return;
    }

    setPos(x()-5,y());

    if(pos().y() + rect().height() >= scene()->height()){
        scene()->removeItem(this);
        delete this;
    }
}
