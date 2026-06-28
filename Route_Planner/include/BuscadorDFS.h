#ifndef BUSCADORDFS_H
#define BUSCADORDFS_H

#include <string>
#include <set>
#include <vector>
#include "BuscadorRota.h"

class BuscadorDFS : public BuscadorRota {
private:
    bool explorar(
        MalhaRodoviaria malha, 
        std::string atual, 
        std::string destino, 
        std::set<std::string>& visitadas, 
        std::vector<Cidade>& caminho, 
        int& distancia
    ); // O motor recursivo que faz o trabalho sujo e pula de cidade em cidade
public:
    Rota buscar(MalhaRodoviaria malha, std::string origem, std::string destino) override; // O método principal que o usuário vai chamar
};

#endif