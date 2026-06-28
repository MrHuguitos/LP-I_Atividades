#ifndef PLANEJADORROTAS_H
#define PLANEJADORROTAS_H

#include <string>
#include "MalhaRodoviaria.h"
#include "BuscadorRota.h"
#include "Rota.h"

class PlanejadorRotas {
private:
    BuscadorRota& buscador; // Guarda apenas uma REFERÊNCIA para qualquer algoritmo que respeite o contrato "BuscadorRota"
public:
    PlanejadorRotas(BuscadorRota& buscador); // O construtor exige que você injete o algoritmo escolhido aqui
    
    Rota planejar(MalhaRodoviaria malha, std::string origem, std::string destino); // O método que o usuário final vai chamar
};

#endif