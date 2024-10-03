#include "Calc.h"

// Función que realiza la operación indicada por 'op' entre los números 'a' y 'b'
// Admite suma, resta, multiplicación y división, con manejo de división por cero.
int Calc::operar(int a, int b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
    else if (op == '/') {
        if (b == 0) {
            throw runtime_error("Error: División por cero");
        }
        return a / b;
    }
    return 0;  // Retorna 0 si el operador no es válido
}

// Función que recorre los números y operadores para obtener el resultado final
int Calc::calcular(int* nums, char* ops, int numCount, int opCount) {
    int res = nums[0];  // Inicializa con el primer número
    for (int i = 0; i < opCount; ++i) {
        res = operar(res, nums[i + 1], ops[i]);  // Aplica la operación secuencialmente
    }
    return res;
}
