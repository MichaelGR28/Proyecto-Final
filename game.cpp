#include "game.h"

Game::Game(QWidget *parent) {
    nivel = 2;

    // Crear timer
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
    timer->start(1200);

    //setFixedSize(1400,700);

    crearMapaDos();
}

void Game::spawn()
{
    enemigo = new Enemigo();
    scene->addItem(enemigo);
    verificarCambioMapa();
    return;
}

void Game::verificarCambioMapa()
{
    if (jugador->x() >= scene->width() - jugador->boundingRect().width()) {
        // Llamar a la función para crear un nuevo mapa
        crearNuevoMapa();
        qDebug() << "Llego a la esquina";
    }
}

void Game::crearNuevoMapa()
{
    // Limpiar la escena actual
    delete scene;

    // Implementar lógica para crear un nuevo mapa según el mapa actual
    // En este ejemplo, alternamos entre dos mapas
    nivel += 1;
    if (nivel == 1) {
        crearMapaUno();
    } else if(nivel == 2) {
        crearMapaDos();
    } else {
        nivel =1;
        crearMapaUno();
    }
}

void Game::crearMapaUno()
{
    // Crear escena
    scene = new QGraphicsScene();
    scene->setSceneRect(40,40,1300,600);

    setScene(scene);

    // Crear jugador
    jugador = new Jugador();
    jugador->setRect(0,0,64,64);
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

    // Crear obstaculo 1
    obstaculo = new Obstaculo(2);
    obstaculo->setRect(0,0,800,5);
    obstaculo->setPos(400,500);

    // Añadir obstaculo a la escena
    scene->addItem(obstaculo);

    // Crear obstaculo 2
    obstaculo = new Obstaculo(2);
    obstaculo->setRect(0,0,300,10);
    obstaculo->setPos(400,300);

    // Añadir obstaculo a la escena
    scene->addItem(obstaculo);

    // Crear obstaculo 3
    obstaculo = new Obstaculo(1);
    obstaculo->setRect(0,0,300,10);
    obstaculo->setPos(800,300);

    // Añadir obstaculo a la escena
    scene->addItem(obstaculo);

    // Crear activador
    activador = new Activador();
    activador->setRect(0,0,50,50);
    activador->setPos(800,100);

    // Añadir activador a la escena
    scene->addItem(activador);

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

    // Crear puerta
    puerta = new Puerta();
    puerta->setRect(0,0,100,900);
    puerta->setPos(300,0);

    // Añadir puerta a la escena
    scene->addItem(puerta);
}

void Game::crearMapaDos()
{
    // Crear escena
    scene = new QGraphicsScene();
    scene->setSceneRect(40,40,1300,600);

    setScene(scene);

    // Crear jugador
    jugador = new Jugador();
    jugador->setRect(0,0,64,64);
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

    // Crear obstaculo 1
    obstaculo = new Obstaculo(0.9);
    obstaculo->setRect(0,0,100,10);
    obstaculo->setPos(400,500);

    // Añadir obstaculo a la escena
    scene->addItem(obstaculo);

    // Crear obstaculo 2
    obstaculo = new Obstaculo(1.5);
    obstaculo->setRect(0,0,100,10);
    obstaculo->setPos(700,500);

    // Añadir obstaculo a la escena
    scene->addItem(obstaculo);

    // Crear obstaculo 3
    obstaculo = new Obstaculo(2);
    obstaculo->setRect(0,0,100,10);
    obstaculo->setPos(1100,500);

    // Añadir obstaculo a la escena
    scene->addItem(obstaculo);

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

    // Crear puerta
    puerta = new Puerta();
    puerta->setRect(0,0,100,900);
    puerta->setPos(300,0);

    // Añadir puerta a la escena
    scene->addItem(puerta);

    // Crear activador
    activador = new Activador();
    activador->setRect(0,0,50,50);
    activador->setPos(1300,300);

    // Añadir activador a la escena
    scene->addItem(activador);
}
