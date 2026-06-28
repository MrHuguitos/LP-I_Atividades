#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

// Clase que armazena os dados de cada pessoa separadamente
class Profile {
public:
    std::string name; // Nome da pessoa
    std::map<std::string, int> dicionario; // Número de sequencias de cada STR
};

class Database {
private:
    std::vector<Profile> profiles; // Vector de objetos. É a lista de Objetos da classe Profile
    std::vector<std::string> strNames; // Todos os tipos de STR da base de dados
public:
    Database();

    bool readCsv(std::string database);
    std::vector<std::string> getStrNames() const;
    std::string search(const std::map<std::string, int>& profile) const;
};

#endif