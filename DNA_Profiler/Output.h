#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>
#include <vector>
#include "Dna.h"

class Output {
public:
    static void usage();
    static void error(const std::string& mensagem);
    static void welcome();
    static void loading(const std::string& descricao, const std::string& caminho, bool ok);
    static void searching();
    static void match(const std::string& nome, const std::string& sequencia, std::vector<StrMatch> matches);
    static void noMatch();
};

#endif