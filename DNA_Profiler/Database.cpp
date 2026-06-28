#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Database.h"

Database::Database() {}

static void limparLinha(std::string& linha) {
    while (!linha.empty() && (linha.back() == '\r' || linha.back() == '\n' || linha.back() == ' ')) {
        linha.pop_back();
    }
}

bool Database::readCsv(std::string database) {
    std::ifstream inf(database); // arquivo que será aberto

    if (!inf) return false;

    std::string strInput; // Variável que armazena o texto da linha atual

    if (std::getline(inf, strInput)) { // Aqui, o strInput recebe o texto da linha inteira
        limparLinha(strInput);
        std::stringstream ss(strInput); // O getline não aceita string comum, então cria-se ss como um stream de strInput
        std::string coluna;

        std::getline(ss, coluna, ','); // ignorar a coluna 'nome'

        while (std::getline(ss, coluna, ',')) {
            strNames.push_back(coluna);
        }
    }
    
    while (std::getline(inf, strInput)) {
        limparLinha(strInput);
        std::stringstream ss(strInput);
        std::string token;

        Profile pessoa;

        std::getline(ss, token, ',');
        pessoa.name = token;
        int i = 0;

        while (std::getline(ss, token, ',')) {
            int valor = std::stoi(token);
            std::string chave = strNames[i];

            pessoa.dicionario[chave] = valor;

            i++;
        }

        profiles.push_back(pessoa);
    }

    inf.close();
    return true;
}

std::vector<std::string> Database::getStrNames() const {
    return strNames;
}

std::string Database::search(const std::map<std::string, int>& profile) const {
    for (const auto& pessoa : profiles) {
        bool combina = true;

        for (const auto& par : pessoa.dicionario) {
            auto it = profile.find(par.first);

            if (it == profile.end() || it->second != par.second) {
                combina = false;
                break;
            }
        }

        if (combina) return pessoa.name;
    }
    
    return "";
}