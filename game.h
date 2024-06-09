#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>

#include "jugador.h"
#include "enemigo.h"
#include "puntaje.h"
#include "vida.h"

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

public slots:
    void spawn();
};
#endif // GAME_H
