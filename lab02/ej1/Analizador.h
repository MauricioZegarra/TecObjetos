#ifndef ANALIZADOR_H
#define ANALIZADOR_H

#include <string>
using namespace std;

// Clase que se encarga de analizar una expresión matemática
// Separa los números y los operadores para su procesamiento
class Analizador {
public:
    int* nums;     // Arreglo dinámico de números extraídos de la expresión
    char* ops;     // Arreglo dinámico de operadores extraídos de la expresión
    int numCount;  // Contador de números en la expresión
    int opCount;   // Contador de operadores en la expresión

    Analizador();  // Constructor para inicializar contadores y punteros
    ~Analizador(); // Destructor para liberar memoria dinámica

    // Función que analiza una expresión matemática (formato: "1+2*3")
    // Extrae los números y operadores, validando que no haya más de 6 números
    void analizar(const string& expr); 
};

#endif
