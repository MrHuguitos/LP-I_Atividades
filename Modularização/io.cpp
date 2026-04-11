#include <iostream>
#include "io.h"
using namespace std;

int readNumber() {
    int numero;

    cout << "Digite um número: ";
    cin >> numero;

    return numero;
}

void writeAnswer(int resultado) {
    cout << resultado << endl;
}