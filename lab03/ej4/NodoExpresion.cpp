#include "NodoExpresion.h"

NodoOperacion::NodoOperacion(char op, unique_ptr<NodoExpresion> izq, unique_ptr<NodoExpresion> der)
    : operacion(op), izquierda(move(izq)), derecha(move(der)) {}  // Inicializa la operación y subárboles

int NodoOperacion::evaluar() const {
    int valorIzq = izquierda->evaluar();  // Evalúa el subárbol izquierdo
    int valorDer = derecha->evaluar(); // Evalúa el subárbol derecho

    // Realiza la operación correspondiente
    if (operacion == '+')
        return valorIzq + valorDer;
    else if (operacion == '*')
        return valorIzq * valorDer;

    return 0;  // Por seguridad, nunca debería llegar aquí
}

NodoNumero::NodoNumero(int v) : valor(v) {}

int NodoNumero::evaluar() const { 
    return valor; // Retorna el valor numérico 
}
