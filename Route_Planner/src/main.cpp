#include <iostream>
#include <string>
#include "../include/MalhaRodoviaria.h"
#include "../include/LeitorArquivo.h"
#include "../include/BuscadorDFS.h"
#include "../include/PlanejadorRotas.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Uso correto: ./routeplanner <arquivo.txt>\n";
        return 1;
    }

    MalhaRodoviaria malha;
    LeitorArquivo leitor(argv[1]);

    leitor.carregar(malha);
    std::cout << "Malha carregada com sucesso!\n";

    BuscadorDFS algoritmoDFS;
    PlanejadorRotas planejador(algoritmoDFS);

    std::string origem, destino, continuar;

    do {
        std::cout << "\nDigite a cidade de origem: ";
        std::getline(std::cin, origem);

        std::cout << "Digite a cidade de destino: ";
        std::getline(std::cin, destino);

        Rota rota = planejador.planejar(malha, origem, destino);

        std::cout << "\n" << rota << "\n";

        std::cout << "\nDeseja buscar outra rota? (s/n): ";
        std::getline(std::cin, continuar);
    } while (continuar == "s" || continuar == "S");
    
    std::cout << "Encerrando o sistema. Boa viagem!\n";
    return 0;
}