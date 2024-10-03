#include "Procesador.h"
#include <iostream>

// Función que procesa una expresión matemática, utiliza un Analizador para separar
// los números y operadores, y un Calc para calcular el resultado.
void Procesador::procesar(const string& expr) {
    try {
        Analizador a;
        a.analizar(expr);  // Analiza la expresión

        Calc calc;
        // Calcula el resultado de la operación usando los números y operadores
        int res = calc.calcular(a.nums, a.ops, a.numCount, a.opCount);

        cout << "Resultado de '" << expr << "' es: " << res << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;  // Muestra el error en caso de ocurrir
    }
}
