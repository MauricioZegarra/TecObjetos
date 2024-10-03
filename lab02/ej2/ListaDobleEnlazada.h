#ifndef LISTA_DOBLE_ENLAZADA_H
#define LISTA_DOBLE_ENLAZADA_H

#include "Nodo.h"

class ListaDobleEnlazada {
private:
    Nodo* cabeza;
    Nodo* cola;

public:
    ListaDobleEnlazada();  // Constructor
    ~ListaDobleEnlazada();  // Destructor

    void insertarFinal(int valor);  // Insertar nodo al final
    bool eliminar(int valor);  // Elimina un nodo
    void mostrar() const;  // Mostrar la lista
};

#endif // LISTA_DOBLE_ENLAZADA_H
