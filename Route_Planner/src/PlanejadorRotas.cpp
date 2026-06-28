#include "PlanejadorRotas.h"

PlanejadorRotas::PlanejadorRotas(BuscadorRota& buscador) : buscador(buscador) {}

Rota PlanejadorRotas::planejar(MalhaRodoviaria malha, std::string origem, std::string destino) {
    return buscador.buscar(malha, origem, destino); // O gerente não faz o trabalho pesado. Ele apenas repassa a missão para o algoritmo!
}