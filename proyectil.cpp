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
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // Eliminar proyectil y enemigo cuando colisionen
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        // Colisiones enemigos
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

            return;
        }

        if (typeid(*(colliding_items[i])) == typeid(Obstaculo)) {

            Obstaculo * obstaculo = dynamic_cast<Obstaculo*>(colliding_items[i]);

            velY = velY + gravedad*tiempo;
            velY = -velY*obstaculo->getCoeficienteE();
            posX0 = pos().x();
            posY0 = pos().y();
            tiempo = 0;
        }

        if (typeid(*(colliding_items[i])) == typeid(Activador)) {
            qDebug() << "Haz golpeado al activador";

            scene()->removeItem(game->puerta);
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete game->puerta;
            delete colliding_items[i];
            delete this;
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
