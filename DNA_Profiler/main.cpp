#include <string>
#include <map>
#include <vector>
#include "Database.h"
#include "Dna.h"
#include "Output.h"

int main(int argc, char* argv[]) {
    if (argc != 5 || std::string(argv[1]) != "-d" || std::string(argv[3]) != "-s") {
        Output::usage();
        return 1;
    }

    std::string database = argv[2];
    std::string dnaSequence = argv[4];

    Output::welcome();

    Database db;
    bool baseOk = db.readCsv(database);

    Output::loading("DNA database file", database, baseOk);

    Dna dna;
    bool dnaOk = dna.readSequence(dnaSequence);

    Output::loading("unknown DNA sequence file", dnaSequence, dnaOk);

    if (!baseOk || !dnaOk) return 1;
    
    Output::searching();

    std::vector<StrMatch> matches = dna.getMatches(db.getStrNames());
    std::map<std::string, int> perfil;

    for (const auto& m : matches) {
        perfil[m.str] = m.count;
    }

    std::string nome = db.search(perfil);

    if (!nome.empty()) Output::match(nome, dna.getSequence(), matches);
    else Output::noMatch();

    return 0;
}