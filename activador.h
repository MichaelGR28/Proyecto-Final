#ifndef ACTIVADOR_H
#define ACTIVADOR_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

class Activador: public QObject,public QGraphicsRectItem {
    Q_OBJECT
public:
    Activador(QGraphicsItem * parent = nullptr);
};

#endif // ACTIVADOR_H
