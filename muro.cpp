#include "muro.h"

Muro::Muro(int _posx, int _posy, int _alto, int _ancho, QGraphicsItem *parent) {
    posx = _posx;
    posy = _posy;
    alto =_alto;
    ancho = _ancho;
}

int Muro::getAlto()
{
    return alto;
}

int Muro::getAncho()
{
    return ancho;
}
