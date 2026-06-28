#include "BuscadorDFS.h"

Rota BuscadorDFS::buscar(MalhaRodoviaria malha, std::string origem, std::string destino) {
    if (!malha.existeCidade(origem) || !malha.existeCidade(destino)) return Rota();

    std::set<std::string> visitadas; // Caderninho de cidades por onde já passamos
    std::vector<Cidade> caminho; // A lista da rota que está sendo formada
    int distancia = 0; // O taxímetro

    bool achou = explorar(malha, origem, destino, visitadas, caminho, distancia); // Dá a partida no motor recursivo!

    if (achou) return Rota(caminho, distancia);

    return Rota();
}

bool BuscadorDFS::explorar(MalhaRodoviaria malha, std::string atual, std::string destino, std::set<std::string>& visitadas, std::vector<Cidade>& caminho, int& distancia) {
    // Passo 1: Cheguei numa cidade! Anoto no caderninho e coloco na rota.
    visitadas.insert(atual);
    caminho.push_back(Cidade(atual));

    // Passo 2: É o destino final? Se sim, VENCEMOS! Para o algoritmo.
    if (atual == destino) return true;

    // Passo 3: Não é o destino. Vamos olhar as placas das estradas vizinhas.
    for (Estrada estrada : malha.getVizinhas(atual)) {
        std::string vizinha = estrada.getDestino().getNome(); // Extrair o nome da cidade vizinha

        // Só entro na estrada se eu AINDA NÃO visitei aquela cidade (evita andar em círculos)
        if (visitadas.find(vizinha) == visitadas.end()) {
            distancia += estrada.getDistancia(); // Ligo o taxímetro

            bool deuCerto = explorar(malha, vizinha, destino, visitadas, caminho, distancia); // MAGIA: Chamo a função de novo, mas agora ESTANDO na cidade vizinha!

            if (deuCerto) return true; // Se o caminho lá na frente achou o destino, repassa o sucesso para trás!

            distancia -= estrada.getDistancia(); // BACKTRACKING (Marcha-ré): Se deu errado, eu cancelo o taxímetro dessa estrada e continuo o loop
        }
    }

    // Se olhei todas as estradas vizinhas e nenhuma deu no destino, é um beco sem saída.
    // Tiro a cidade atual da rota e dou "marcha-ré" para a cidade anterior.
    caminho.pop_back();
    return false;
}