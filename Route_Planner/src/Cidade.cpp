#include "../include/Cidade.h"

Cidade::Cidade(std::string nome) : nome(nome) {}

std::string Cidade::getNome() const {
    return nome;
}

// Ensina o C++ que duas cidades são iguais se tiverem o mesmo nome
bool Cidade::operator==(const Cidade& outra) const {
    return this->nome == outra.nome;
}

// Ensina o C++ a colocar as cidades em ordem alfabética (necessário para o std::set depois)
bool Cidade::operator<(const Cidade& outra) const {
    return this->nome < outra.nome;
}

// Ensina o C++ a imprimir apenas o nome da cidade no terminal
std::ostream& operator<<(std::ostream& saida, const Cidade& cidade) {
    saida << cidade.getNome();

    return saida;
}