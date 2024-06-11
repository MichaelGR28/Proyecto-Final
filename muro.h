#ifndef MURO_H
#define MURO_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

#include <QDebug>

class Muro: public QObject,public QGraphicsRectItem {
    Q_OBJECT
public:
    Muro(int _posx, int _posy, int _alto, int _ancho, QGraphicsItem * parent = nullptr);
    int getAlto();
    int getAncho();
private:
    int posx;
    int posy;
    int alto;
    int ancho;
};

#endif // MURO_H
