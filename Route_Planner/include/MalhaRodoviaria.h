#ifndef MALHARODOVIARIA_H
#define MALHARODOVIARIA_H

#include <string>
#include <vector>
#include <map>
#include "Cidade.h"
#include "Estrada.h"

class MalhaRodoviaria {
private:
    // Dicionário com o nome da cidade como chave e que aponta para uma lista de estradas
    std::map<std::string, std::vector<Estrada>> conexoes;
public:
    void adicionarCidade(Cidade cidade);
    void adicionarEstrada(Estrada estrada);
    bool existeCidade(std::string nome) const;
    std::vector<Estrada> getVizinhas(std::string nome) const;
};

#endif