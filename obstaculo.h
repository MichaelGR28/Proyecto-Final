#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

class Obstaculo: public QObject,public QGraphicsRectItem {
public:
    Obstaculo(float _coeficienteE, QGraphicsItem * parent = nullptr);
    float getCoeficienteE();
private:
    float coeficienteE;
};

#endif // OBSTACULO_H
