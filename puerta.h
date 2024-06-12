#ifndef PUERTA_H
#define PUERTA_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

class Puerta: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Puerta(QGraphicsItem * parent = nullptr);
};

#endif // PUERTA_H
