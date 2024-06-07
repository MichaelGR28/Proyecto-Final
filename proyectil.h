#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QObject>

class Proyectil: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Proyectil(int _vel_x, int _vel_y, int _pos_x0, int _pos_y0);
    int calcular_posicion_y();
    int calcular_posicion_x();
public slots:
    void move();
private:
    float vel_x;
    float vel_y;
    float pos_x0;
    float pos_y0;
    float gravedad = 200;
    float t = 0;
};

#endif // PROYECTIL_H
