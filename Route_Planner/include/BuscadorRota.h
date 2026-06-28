#ifndef BUSCADORROTA_H
#define BUSCADORROTA_H

#include <string>
#include "MalhaRodoviaria.h"
#include "Rota.h"

class BuscadorRota {
public:
    virtual Rota buscar(MalhaRodoviaria malha, std::string origem, std::string destino) = 0;
};

#endif