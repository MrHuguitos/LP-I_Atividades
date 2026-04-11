#include <iostream>
#include "io.h"
using namespace std;

int main() {
    int soma = readNumber() + readNumber();

    writeAnswer(soma);

    return 0;
}