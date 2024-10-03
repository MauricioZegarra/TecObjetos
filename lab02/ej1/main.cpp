#include "Procesador.cpp"
#include "Analizador.cpp"
#include "Calc.cpp"

#include <iostream>
#include <string>

using namespace std;

// Función recursiva que pide al usuario una expresión matemática para procesar
void ejecutar() {
    string expr;
    cout << "Ingresa una expresión matemática (o deja en blanco para salir): ";
    getline(cin, expr);

    if (!expr.empty()) {
        Procesador p;
        p.procesar(expr);  // Procesa la expresión ingresada
        cout << endl;

        ejecutar();  // Llama a sí misma para pedir otra expresión
    } else {
        cout << "Cerrando calculadora..." << endl;
    }
}

int main() {
    ejecutar();  // Inicia el proceso interactivo
    return 0;
}
