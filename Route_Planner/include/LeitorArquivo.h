#ifndef LEITORARQUIVO_H
#define LEITORARQUIVO_H

#include <string>
#include "MalhaRodoviaria.h"

class LeitorArquivo {
private:
    std::string caminho;
public:
    LeitorArquivo(std::string caminho);
    
    void carregar(MalhaRodoviaria& malha);
};

#endif