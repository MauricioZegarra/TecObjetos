#ifndef PROCESADOR_H
#define PROCESADOR_H

#include <string>
#include "Analizador.h"
#include "Calc.h"

using namespace std;

// Clase que procesa una expresión matemática.
// Utiliza un Analizador para separar la expresión y un Calc para calcular el resultado.
class Procesador {
public:
    // Función que procesa la expresión, manejando errores si ocurren
    void procesar(const string& expr);
};

#endif
