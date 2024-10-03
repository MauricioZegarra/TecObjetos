#ifndef CALC_H
#define CALC_H

// Clase que realiza cálculos sobre los números y operadores proporcionados
class Calc {
public:
    // Realiza una operación entre dos números dados un operador
    int operar(int a, int b, char op);
    
    // Calcula el resultado final utilizando los números y operadores
    int calcular(int* nums, char* ops, int numCount, int opCount);
};

#endif
