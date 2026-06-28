#include <iostream>
#include <fstream>
#include <sstream>
#include "Util.h"
#include "LeitorArquivo.h"

LeitorArquivo::LeitorArquivo(std::string caminho) : caminho(caminho) {}

void LeitorArquivo::carregar(MalhaRodoviaria& malha) {
    std::ifstream arquivo(caminho);

    if (!arquivo.is_open()) {
        std::cerr << "Erro: Não foi possível abrir o arquivo " << caminho << "\n";

        return;
    }

    std::string linha;

    while (std::getline(arquivo, linha)) {
        if (util::trim(linha).empty()) continue; // Pula linhas vazias que podem estar perdidas no arquivo

        std::stringstream ss(linha);
        std::string origemTexto, destinoTexto, distanciaTexto;

        std::getline(ss, origemTexto, ';');
        std::getline(ss, destinoTexto, ';');
        std::getline(ss, distanciaTexto, ';');

        std::string origemLimpa = util::trim(origemTexto);
        std::string destinoLimpo = util::trim(destinoTexto);
        std::string distanciaLimpa = util::trim(distanciaTexto);

        try {
            int distancia = std::stoi(distanciaLimpa);

            // Criação das cidades (origem e destino)
            // Criação da estrada (Origem -> Destino)
            // Adiciona a malha
            malha.adicionarEstrada(Estrada(Cidade(origemLimpa), Cidade(destinoLimpo), distancia));
        }
        catch(...) {
            std::cerr << "Erro ao processar a distancia na linha: " << linha << "\n";
        } 
    }
    
    arquivo.close();
}