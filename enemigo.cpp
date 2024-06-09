#include "enemigo.h"
#include "game.h"
#include "jugador.h"

extern Game * game;

Enemigo::Enemigo(QGraphicsItem *parent): QObject(), QGraphicsRectItem() {
    int random_number = rand() % 700;
    setPos(random_number,0);

    setRect(0,0,100,100);

    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(movimiento()));

    timer->start(50);

}

void Enemigo::movimiento()
{
    if(pos().y() + game->jugador->rect().width() >= scene()->height() - game->jugador->rect().height()){
        if(((game->jugador->pos().x() <= this->pos().x()) && (game->jugador->pos().x() + game->jugador->rect().width()) >= this->pos().x()) || ((game->jugador->pos().x() >= this->pos().x()) && (game->jugador->pos().x()) <= this->pos().x() + this->rect().width())){
            game->vida->quitarVida();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    setPos(x(),y()+5);

    if(pos().y() + rect().height() >= scene()->height()){
        scene()->removeItem(this);
        delete this;
    }
}
