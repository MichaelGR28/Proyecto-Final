#ifndef PUNTAJE_H
#define PUNTAJE_H

#include <QGraphicsTextItem>
#include <QFont>

class Puntaje: public QGraphicsTextItem {
public:
    Puntaje(QGraphicsItem * parent = nullptr);
    void incrementarPuntuacion();
    int getPuntuacion();
private:
    int puntuacion;
};

#endif // PUNTAJE_H
