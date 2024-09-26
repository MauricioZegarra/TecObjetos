#include <iostream>
#include <vector>

using namespace std;

// Función para obtener los dígitos de un número
vector<int> obtener_digitos(int num) {
    vector<int> digitos;
    while (num > 0) {
        digitos.push_back(num % 10);
        num /= 10;
    }
    return digitos;
}

// Función para verificar si un número es cubo perfecto
bool es_cubo_perfecto(int num) {
    vector<int> digitos = obtener_digitos(num);
    int suma = 0;

    for (int digito : digitos) {
        suma += digito * digito * digito;  // Suma del cubo de los dígitos
    }

    return suma == num;  // Verificar si la suma es igual al número original
}

int main() {

    char next; //variable para continuar ingresando números

    do {
        int numero;
        cout << "\nIngrese un número: ";
        cin >> numero;
        if (es_cubo_perfecto(numero)) {
            cout << numero << " es un cubo perfecto.\n";
        } 
        else {
            cout << numero << " no es un cubo perfecto.\n";
        }

        cout << "\n¿Ingresar más números? (S/N) -> ";
        cin >> next;
    }
    while (next == 'S');

    return 0;
}
