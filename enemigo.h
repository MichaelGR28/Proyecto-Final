#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

#include <QDebug>


class Enemigo: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Enemigo(QGraphicsItem * parent = nullptr);

    QTimer * timer;
public slots:
    void movimiento();
};

#endif // ENEMIGO_H
