#ifndef VIDA_H
#define VIDA_H

#include <QGraphicsTextItem>
#include <QFont>

class Vida: public QGraphicsTextItem {
public:
    Vida(QGraphicsItem * parent = nullptr);
    void quitarVida();
    void incrementarVida();
private:
    int vida;
};

#endif // VIDA_H
