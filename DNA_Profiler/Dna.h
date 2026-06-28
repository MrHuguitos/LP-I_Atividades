#ifndef DNA_H
#define DNA_H

#include <iostream>
#include <string>
#include <vector>

struct StrMatch {
    std::string str;
    int count;
    int start;
};

class Dna {
private:
    std::string sequencia;
public:
    Dna();

    bool readSequence(std::string arquivo);
    std::string getSequence() const;
    int countMaxConsecutiveSTRs(const std::string& str, int& start) const;
    std::vector<StrMatch> getMatches(const std::vector<std::string>& strNames) const;
};

#endif