#include "NodoExpresion.cpp"
#include <iostream>
using namespace std;  // Usamos el espacio de nombres estándar

int main() {
    // Creamos un árbol de expresión: 3 + (5 * 2)
    unique_ptr<NodoExpresion> expresion =
        make_unique<NodoOperacion>('+',
            make_unique<NodoNumero>(3),
            make_unique<NodoOperacion>('*',
                make_unique<NodoNumero>(5),
                make_unique<NodoNumero>(2)
            )
        );

    // Evaluamos la expresión
    cout << "Resultado: " << expresion->evaluar() << endl;  // Resultado: 13

    return 0;
}
