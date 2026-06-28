#include <iostream>
#include <fstream>
#include <string>
#include "Dna.h"

Dna::Dna() {}

bool Dna::readSequence(std::string arquivo) {
    std::ifstream inf(arquivo);

    if (!inf) return false;

    std::getline(inf, sequencia);

    while (!sequencia.empty() && (sequencia.back() == '\r' || sequencia.back() == '\n' || sequencia.back() == ' ')) {
        sequencia.pop_back();
    }

    inf.close();
    return true;
}

std::string Dna::getSequence() const {
    return sequencia;
}

int Dna::countMaxConsecutiveSTRs(const std::string& str, int& start) const {
    int maiorSequencia = 0;
    start = -1;
    int tamanhoStr = str.length();
    int tamanhoSequencia = sequencia.length();

    if (tamanhoStr == 0) return 0;

    for (int i = 0; i < tamanhoSequencia; i++) {
        int contador = 0;
        int posicaoAtual = i;

        while ((posicaoAtual + tamanhoStr <= tamanhoSequencia) && (sequencia.compare(posicaoAtual, tamanhoStr, str) == 0)) {
            contador++;
            posicaoAtual += tamanhoStr;
        }

        if (contador > maiorSequencia) {
            maiorSequencia = contador;
            start = i;
        }
    }

    return maiorSequencia;
}

std::vector<StrMatch> Dna::getMatches(const std::vector<std::string>& strNames) const {
    std::vector<StrMatch> resultado;

    for (const auto& str : strNames) {
        int start;
        int count = countMaxConsecutiveSTRs(str, start);
        resultado.push_back({str, count, start});
    }

    return resultado;
}