#include "game.h"

Game::Game(QWidget *parent) {
    // Crear timer
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
    timer->start(2000);

    // Crear escena
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    setScene(scene);
    setFixedSize(900,700);

    // Crear jugador
    jugador = new Jugador();
    jugador->setRect(0,0,100,100);
    jugador->setPos(scene->width()/2,scene->height()-jugador->rect().height());

    jugador->setFlag(QGraphicsItem::ItemIsFocusable);
    jugador->setFocus();

    // Añadir jugador a la escena
    scene->addItem(jugador);

    // Crear puntaje
    puntaje = new Puntaje();
    puntaje->setPos(scene->width() - puntaje->boundingRect().width(),0);


    // Añadir puntaje a la escena
    scene->addItem(puntaje);

    // Crear vida
    vida = new Vida();
    vida->setPos(0,0);

    // Añadir vida a la escena
    scene->addItem(vida);
}

void Game::spawn()
{
    enemigo = new Enemigo();
    scene->addItem(enemigo);
}
