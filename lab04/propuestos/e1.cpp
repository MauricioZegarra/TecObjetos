#include <iostream>
#include <vector>
#include <algorithm> // Para std::count_if
#include <cstdlib>    // Para rand()
#include <ctime>      // Para srand(time(0))

using namespace std;

int main() {
    // Inicializamos el generador de números aleatorios
    srand(time(0));

    // Creamos un vector de números aleatorios
    vector<int> numeros;
    for (int i = 0; i < 20; ++i) {
        int num = rand() % 100;
        numeros.push_back(num); // Números entre 0 y 99
        cout << num << ", ";
    }

    // Contamos los números impares y menores de 20
    int imparesMenores20 = count_if(numeros.begin(), numeros.end(), [](int num) {
        return num < 20 && num % 2 != 0;
    });

    // Mostramos el resultado
    cout << "\n\nCantidad de números impares menores de 20: " << imparesMenores20 << endl;

    return 0;
}
