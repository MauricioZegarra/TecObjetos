#include "Analizador.h"
#include <stdexcept>  // Para lanzar excepciones

// Constructor que inicializa los arreglos y contadores en null o 0
Analizador::Analizador() : nums(nullptr), ops(nullptr), numCount(0), opCount(0) {}

// Destructor que libera la memoria dinámica asignada a los arreglos
Analizador::~Analizador() {
    delete[] nums;
    delete[] ops;
}

// Función que analiza la expresión recibida y la divide en números y operadores
void Analizador::analizar(const string& expr) {
    numCount = 0;  // Reinicia contadores
    opCount = 0;

    // Primer recorrido: contar números y operadores
    for (size_t i = 0; i < expr.size(); ++i) {
        if (expr[i] >= '0' && expr[i] <= '9') {  // Si es un dígito
            if (numCount == 0 || !(expr[i - 1] >= '0' && expr[i - 1] <= '9')) {
                numCount++;  // Incrementa el contador de números
            }
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            opCount++;  // Incrementa el contador de operadores
        }
    }

    // Verifica que no haya más de 6 números en la expresión
    if (numCount > 6) {
        throw runtime_error("Error: Se permiten como máximo 6 números en la operación.");
    }

    // Asignar memoria para los arreglos de números y operadores
    nums = new int[numCount];
    ops = new char[opCount];

    // Segundo recorrido: extraer números y operadores
    string num;
    int numIdx = 0, opIdx = 0;
    for (size_t i = 0; i < expr.size(); ++i) {
        if (expr[i] >= '0' && expr[i] <= '9') {
            num += expr[i];  // Construye el número
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            nums[numIdx++] = stoi(num);  // Almacena el número convertido
            ops[opIdx++] = expr[i];      // Almacena el operador
            num = "";                    // Reinicia para el siguiente número
        }
    }
    nums[numIdx] = stoi(num);  // Almacena el último número
}
