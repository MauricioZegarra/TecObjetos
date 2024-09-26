#include <iostream>
#include <vector>

using namespace std;

// Función para obtener los divisores de un número
vector<int> obtener_divisores(int num) {
    vector<int> divisores;
    for (int i = 1; i <= num; ++i) {
        if (num % i == 0) {
            divisores.push_back(i);
        }
    }
    return divisores;
}

int main() {

    char next; //Variable para volver a ingresar números

    do {
        int numero;
        cout << "\nIngrese un número: ";
        cin >> numero;

        vector<int> divisores = obtener_divisores(numero);

        // Imprimir los divisores
        cout << "Divisores de " << numero << ": ";
        for (int divisor : divisores) {
            cout << divisor << " ";
        }
        cout << endl;
    
        // Imprimir la cantidad de divisores
        cout << "Cantidad de divisores: " << divisores.size() << endl;

        cout << "\n¿Volver a ingresar un número? (S/N) -> ";
        cin >> next;
    }
    while(next == 'S');

    return 0;
}
