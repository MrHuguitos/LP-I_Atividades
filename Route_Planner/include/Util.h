#ifndef UTIL_H
#define UTIL_H

#include <string>

namespace util {
    // Função para remover espaços em branco do início e do fim de um texto
    inline std::string trim(std::string texto) {
        size_t primeiro = texto.find_first_not_of(' '); // Acha a primeira letra que não é um espaço

        if (primeiro == std::string::npos) return ""; // Se for tudo espaço, retorna vazio
        
        size_t ultimo = texto.find_last_not_of(' '); // Acha a última letra que não é espaço

        return texto.substr(primeiro, (ultimo - primeiro + 1)); // Corta a string pegando apenas o miolo útil
    }
}

#endif