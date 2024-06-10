#include "game.h"

Game::Game(QWidget *parent) {
    // Crear timer
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
    timer->start(1200);

    // Crear escena
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1300,600);

    setScene(scene);
    setFixedSize(1400,700);

    // Crear jugador
    jugador = new Jugador();
    jugador->setRect(0,0,100,100);
    jugador->setPos(0,250);
    jugador->posicionInicial();

    jugador->setFlag(QGraphicsItem::ItemIsFocusable);
    jugador->setFocus();

    // Añadir jugador a la escena
    scene->addItem(jugador);

    // Crear muro
    muro = new Muro(0, 550, 1400, 100);
    muro->setRect(0,0,1400,100);
    muro->setPos(0, 550);

    // Añadir muro a la escena
    scene->addItem(muro);

    // Crear muro 2
    muro = new Muro(400,420,300,100);
    muro->setRect(0,0,300,130);
    muro->setPos(400, 420);

    // Añadir muro 2 a la escena
    scene->addItem(muro);

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
    //enemigo = new Enemigo();
    //scene->addItem(enemigo);
    return;
}
