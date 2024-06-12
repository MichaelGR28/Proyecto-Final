#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QPainter>
#include <QRectF>

#include "jugador.h"
#include "enemigo.h"
#include "puntaje.h"
#include "vida.h"
#include "muro.h"
#include "obstaculo.h"
#include "activador.h"
#include "puerta.h"

#include <QDebug>

class Game :public QGraphicsView
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);

    QGraphicsScene * scene;
    QTimer * timer;
    Enemigo * enemigo;
    Jugador * jugador;
    Puntaje * puntaje;
    Vida * vida;
    Muro * muro;
    Obstaculo * obstaculo;
    Activador * activador;
    Puerta * puerta;

public slots:
    void spawn();
    void verificarCambioMapa();
    void crearNuevoMapa();
private:
    void crearMapaUno();
    void crearMapaDos();
    int nivel;

};
#endif // GAME_H
