#ifndef ESTRADA_H
#define ESTRADA_H

#include <ostream>
#include "Cidade.h"

class Estrada {
private:
    Cidade origem;
    Cidade destino;
    int distancia;
public:
    Estrada(Cidade origem, Cidade destino, int distancia);

    Cidade getOrigem() const;
    Cidade getDestino() const;
    int getDistancia() const;
};

std::ostream& operator<<(std::ostream& saida, const Estrada& estrada);

#endif