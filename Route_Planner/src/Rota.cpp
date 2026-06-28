#include "Rota.h"

Rota::Rota() : encontrada(false), distanciaTotal(0) {}
Rota::Rota(std::vector<Cidade> caminho, int distanciaTotal) : encontrada(true), caminho(caminho), distanciaTotal(distanciaTotal) {}

bool Rota::foiEncontrada() const {
    return encontrada;
}

std::ostream& operator<<(std::ostream& saida, const Rota& rota) {
    if (!rota.encontrada) return saida << "Não há rota disponível.";

    saida << "Rota encontrada:\n";
    for (size_t i = 0; i < rota.caminho.size(); i++) {
        saida << rota.caminho[i];

        if (i < rota.caminho.size() - 1) saida << " -> ";
    }
    
    return saida << "\nDistância total: " << rota.distanciaTotal << " km";
}