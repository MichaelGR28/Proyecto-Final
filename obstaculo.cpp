#include "obstaculo.h"

Obstaculo::Obstaculo(float _coeficienteE, QGraphicsItem *parent) {
    coeficienteE = _coeficienteE;
}

float Obstaculo::getCoeficienteE()
{
    return coeficienteE;
}
