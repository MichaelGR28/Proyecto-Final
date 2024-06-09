#include "proyectil.h"
#include "game.h"

extern Game * game;

Proyectil::Proyectil(int _velX, int _velY, QGraphicsItem *parent)
{
    velX = _velX;
    velY = _velY;

    setRect(0,0,20,20);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(movimiento()));

    timer->start(50);
}

void Proyectil::posicionInicial()
{
    posX0 = pos().x();
    posY0 = pos().y();
}

void Proyectil::movimiento()
{
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemigo)){
            // Incrementar puntuacion
            game->puntaje->incrementarPuntuacion();

            game->vida->incrementarVida();

            // Eliminar de la escena el enemigo y el proyectil
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // Eliminar el enemigo y el proyectil
            delete colliding_items[i];
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
    }

    tiempo += 0.05;
    setPos(posX0 + velX*tiempo, posY0 + velY*tiempo + (gravedad/2)*tiempo*tiempo);

    if(pos().y() + rect().height() >= scene()->height()){
        scene()->removeItem(this);
        delete this;
    }
}
