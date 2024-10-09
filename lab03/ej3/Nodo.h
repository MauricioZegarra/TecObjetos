#ifndef NODO_H
#define NODO_H

// Clase Nodo para una lista doblemente enlazada
class Nodo {
public:
    int valor;      // Valor almacenado en el nodo
    Nodo* siguiente;  // Puntero al siguiente nodo
    Nodo* anterior;  // Puntero al nodo anterior

    Nodo(int v) : valor(v), siguiente(nullptr), anterior(nullptr) {}  // Constructor
};

#endif
