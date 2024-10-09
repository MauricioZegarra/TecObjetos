#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H

#include "Nodo.h"

class ListaDoble {
private:
    Nodo* cabeza;  // Primer nodo de la lista
    Nodo* cola;    // Último nodo de la lista

public:
    ListaDoble();   // Constructor
    ~ListaDoble();  // Destructor para liberar memoria
    void agregar(int valor);  // Agrega un nodo al final de la lista
    void imprimirDesdeAdelante() const;  // Imprime la lista desde el inicio
    void imprimirDesdeAtras() const;     // Imprime la lista desde el final
    Nodo* buscarDesdeAdelante(int valor) const;  // Busca un valor desde el inicio
    Nodo* buscarDesdeAtras(int valor) const;     // Busca un valor desde el final
};

#endif
