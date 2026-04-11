#include <iostream>
#include <iomanip>
using namespace std;

double porcentagem(int arr[], int tamanho) {
    return (arr[tamanho - 2] * 100.00) / arr[tamanho - 1];
}

int main() {
    int numeros[2];

    while (true) {
        cout << "Digite 2 numeros:" << endl;

        for(int i = 0; i < 2; i++) {
            cin >> numeros[i];
        };

        if (numeros[0] <= numeros[1]) {
            cout << fixed << setprecision(2) << porcentagem(numeros, 2) << "%" << endl;
            break;
        } else {
            cout << "Erro! Entre com um primeiro valor menor ou igual ao segundo." << endl;
        };
    }

    return 0;
}