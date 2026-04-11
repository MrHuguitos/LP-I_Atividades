#include <iostream>
#include <iomanip>
using namespace std;

double media(int arr[], int tamanho) {
    if (tamanho == 1) return arr[0];

    return (arr[tamanho - 1] + (media(arr, tamanho - 1) * (tamanho - 1))) / tamanho;
}

int main() {
    int numeros[3];

    cout << "Digite 3 numeros:" << endl;

    for(int i = 0; i < 3; i++) {
        cin >> numeros[i];
    };

    cout << fixed << setprecision(2) << media(numeros, 3) << endl;

    return 0;
}