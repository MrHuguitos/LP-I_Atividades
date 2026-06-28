#include "Estrada.h"

Estrada::Estrada(Cidade origem, Cidade destino, int distancia) : origem(origem), destino(destino), distancia(distancia) {}

Cidade Estrada::getOrigem() const {
    return origem;
}

Cidade Estrada::getDestino() const {
    return destino;
}

int Estrada::getDistancia() const {
    return distancia;
}

// Ensina o C++ a imprimir: "Origem --distancia-- Destino"
std::ostream& operator<<(std::ostream& saida, const Estrada& estrada) {
    saida << estrada.getOrigem() << " --" << estrada.getDistancia() << "-- " << estrada.getDestino();

    return saida;
}