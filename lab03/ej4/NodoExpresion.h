#ifndef NODOEXPRESION_H
#define NODOEXPRESION_H

#include <memory>
using namespace std;  // Usamos el espacio de nombres estándar

// Clase abstracta para los nodos del árbol de expresiones
class NodoExpresion {
public:
    virtual int evaluar() const = 0;  // Método para evaluar el nodo
    virtual ~NodoExpresion() = default;
};

// Nodo que representa una operación (+ o *)
class NodoOperacion : public NodoExpresion {
private:
    char operacion;  // Operación a realizar (+ o *)
    unique_ptr<NodoExpresion> izquierda;  // Subárbol izquierdo
    unique_ptr<NodoExpresion> derecha;    // Subárbol derecho

public:
    NodoOperacion(char op, unique_ptr<NodoExpresion> izq, unique_ptr<NodoExpresion> der);
    int evaluar() const override;  // Evalúa la operación
};

// Nodo que representa un número
class NodoNumero : public NodoExpresion {
private:
    int valor;  // Valor numérico

public:
    NodoNumero(int v);
    int evaluar() const override;  // Retorna el valor numérico
};

#endif
