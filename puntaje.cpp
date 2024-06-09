#include "puntaje.h"

Puntaje::Puntaje(QGraphicsItem *parent): QGraphicsTextItem() {
    // Inicializar puntuacion
    puntuacion = 0;

    // Dibujar el texto
    setPlainText(QString("Score: ") + QString::number(puntuacion)); // Score: 0
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
}

void Puntaje::incrementarPuntuacion() {
    puntuacion += 10;
    setPlainText(QString("Score: ") + QString::number(puntuacion));
}

int Puntaje::getPuntuacion() {
    return puntuacion;
}
