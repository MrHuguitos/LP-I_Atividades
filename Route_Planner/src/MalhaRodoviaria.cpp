#include "../include/MalhaRodoviaria.h"

void MalhaRodoviaria::adicionarCidade(Cidade cidade) {
    std::string nome = cidade.getNome();

    if (!existeCidade(nome)) conexoes[nome] = std::vector<Estrada>();
}

void MalhaRodoviaria::adicionarEstrada(Estrada estrada) {
    Cidade origem = estrada.getOrigem();
    Cidade destino = estrada.getDestino();
    int distancia = estrada.getDistancia();

    adicionarCidade(origem);
    adicionarCidade(destino);

    conexoes[origem.getNome()].push_back(estrada);

    Estrada volta(destino, origem, distancia);
    conexoes[destino.getNome()].push_back(volta);
}

bool MalhaRodoviaria::existeCidade(std::string nome) const {
    return conexoes.find(nome) != conexoes.end(); // Eu procurei a cidade e o resultado NÃO FOI o espaço vazio no final da lista
}

std::vector<Estrada> MalhaRodoviaria::getVizinhas(std::string nome) const {
    if (existeCidade(nome)) return conexoes.at(nome); // Se a chave existir, ele devolve os dados. Se a chave não existir, em vez de criar uma nova, ele "grita" e trava o programa jogando um erro (uma exceção std::out_of_range).
    
    return {}; // Retorna uma lista vazia se a cidade for um fantasma
}