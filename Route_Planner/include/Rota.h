#ifndef ROTA_H
#define ROTA_H

#include <vector>
#include <string>
#include <ostream>
#include "Cidade.h"

class Rota {
private:
    bool encontrada;
    std::vector<Cidade> caminho;
    int distanciaTotal;
public:
    Rota(); // Rota falha (não encontrou caminho)
    Rota(std::vector<Cidade> caminho, int distanciaTotal); // Rota encontrada

    bool foiEncontrada() const;
    friend std::ostream& operator<<(std::ostream& saida, const Rota& rota);
};

#endif