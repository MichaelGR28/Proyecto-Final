#include "vida.h"

Vida::Vida(QGraphicsItem *parent): QGraphicsTextItem() {
    // Inicializar vida
    vida = 100;

    setPlainText(QString("HP: ") + QString::number(vida)); // Score: 0
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Vida::quitarVida() {
    vida -= 10;
    setPlainText(QString("Score: ") + QString::number(vida));
}

void Vida::incrementarVida() {
    if(vida < 100){
        vida += 1;
        setPlainText(QString("Score: ") + QString::number(vida));
    }
}
