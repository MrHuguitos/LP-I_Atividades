#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include "Output.h"

namespace {
    const std::string RESET = "\033[0m";
    const std::string VERDE = "\033[1;32m";
    const std::string VERMELHO = "\033[1;31m";
    const std::string AZUL = "\033[1;34m";

    const int LARGURA = 80;
    const int LARGURA_SEQ = 80;

    void linha() {
        std::cout << std::string(LARGURA, '=') << "\n";
    }

    void centralizar(const std::string& texto) {
        int espacos = (LARGURA - (int)texto.size()) / 2;
        if (espacos < 0) espacos = 0;
        std::cout << std::string(espacos, ' ') << texto << "\n";
    }

    std::string aparar(std::string s) {
        while (!s.empty() && s.back() == ' ') s.pop_back();
        return s;
    }
}

void Output::usage() {
    std::cout << "Uso: dnaprofiler -d <database_file> -s <dna_sequence_file>\n";
    std::cout << "  Onde os argumentos são:\n";
    std::cout << "      <database_file>     O arquivo correspondente a base de DNA.\n";
    std::cout << "      <dna_sequence_file> O arquivo contendo a sequência de DNA você deseja identificar.\n";
}

void Output::error(const std::string& mensagem) {
    std::cerr << VERMELHO << mensagem << RESET << "\n";
}

void Output::welcome() {
    linha();
    centralizar("Welcome to the C++ DNA Profiler, v1.0");
    centralizar("Copyright (C) 2026, Trio Paradadura");
    linha();
    std::cout << "\n";
    std::cout << AZUL << "This programa loads a DNA database and an unknown DNA sequence and tries\n";
    std::cout << "to find a match between the input DNA sequence and the DNA database." << RESET << "\n\n";
}

void Output::loading(const std::string& descricao, const std::string& caminho, bool ok) {
    std::cout << "[+] Loading " << descricao << " [" << VERMELHO << caminho << RESET << "] ... ";
    if (ok) {
        std::cout << VERDE << "[OK]" << RESET << "\n";
    } else {
        std::cout << VERMELHO << "[FAIL]" << RESET << "\n";
    }
}

void Output::searching() {
    std::cout << "[+] Searching the database for a match... Please wait.\n";

    int largura = 78;
    for (int p = 0; p <= largura; p++) {
        std::cout << "\r[" << std::string(p, '=') << std::string(largura - p, ' ')
                  << "] " << (p * 100 / largura) << " %" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(6));
    }
    std::cout << "\n\n";
}

void Output::match(const std::string& nome, const std::string& sequencia, std::vector<StrMatch> matches) {
    std::cout << "Match ID (99.9%): " << nome << "\n\n";

    std::sort(matches.begin(), matches.end(), [](const StrMatch& a, const StrMatch& b) {
        return a.start < b.start;
    });

    int tamSeq = (int)sequencia.size();
    std::vector<bool> destaque(tamSeq, false);
    std::string marcadores(tamSeq, ' ');
    std::string rotulos(tamSeq, ' ');

    for (const auto& m : matches) {
        if (m.count <= 0 || m.start < 0) continue;

        int largura = m.count * (int)m.str.size();
        for (int j = m.start; j < m.start + largura && j < tamSeq; j++) {
            destaque[j] = true;
            marcadores[j] = 'v';
        }

        std::string rotulo = m.str + " [x" + std::to_string(m.count) + "]";
        int pos = m.start + (largura - (int)rotulo.size()) / 2;
        if (pos < 0) pos = m.start;
        if ((int)rotulos.size() < pos + (int)rotulo.size()) {
            rotulos.resize(pos + rotulo.size(), ' ');
        }
        for (int k = 0; k < (int)rotulo.size(); k++) {
            rotulos[pos + k] = rotulo[k];
        }
    }

    for (int b = 0; b < tamSeq; b += LARGURA_SEQ) {
        int e = b + LARGURA_SEQ;
        if (e > tamSeq) e = tamSeq;

        bool temMatch = false;
        for (int i = b; i < e; i++) {
            if (destaque[i]) {
                temMatch = true;
                break;
            }
        }

        if (temMatch) {
            std::cout << aparar(rotulos.substr(b, e - b)) << "\n";
            std::cout << VERDE << aparar(marcadores.substr(b, e - b)) << RESET << "\n";
        }

        bool aberto = false;
        for (int i = b; i < e; i++) {
            if (destaque[i] && !aberto) {
                std::cout << VERDE;
                aberto = true;
            }
            if (!destaque[i] && aberto) {
                std::cout << RESET;
                aberto = false;
            }
            std::cout << sequencia[i];
        }
        if (aberto) std::cout << RESET;
        std::cout << "\n";
    }
}

void Output::noMatch() {
    std::cout << ">>> Sorry, no match found in our database.\n";
}