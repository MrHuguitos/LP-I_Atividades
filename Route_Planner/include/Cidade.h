#ifndef CIDADE_H
#define CIDADE_H

#include <string>
#include <ostream>

class Cidade {
private:
    std::string nome;
public:
    Cidade(std::string nome);
    
    std::string getNome() const;

    // Operadores lógicos (Essenciais para o C++ conseguir buscar e ordenar as cidades)    
    bool operator==(const Cidade& outra) const;
    bool operator<(const Cidade& outra) const;
};

// Operador para permitir fazer: std::cout << cidade;
std::ostream& operator<<(std::ostream& saida, const Cidade& cidade);

#endif