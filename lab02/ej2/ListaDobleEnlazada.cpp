#include <iostream>
#include "ListaDobleEnlazada.h"

using namespace std;

// Constructor
ListaDobleEnlazada::ListaDobleEnlazada() : cabeza(nullptr), cola(nullptr) {}

// Destructor
ListaDobleEnlazada::~ListaDobleEnlazada() {
    Nodo* temp;
    while (cabeza) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

// Insertar al final
void ListaDobleEnlazada::insertarFinal(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->valor = valor;
    nuevo->siguiente = nullptr;
    nuevo->anterior = cola;

    if (cola) {
        cola->siguiente = nuevo;
    } else {
        cabeza = nuevo;
    }
    cola = nuevo;
}

// Eliminar un nodo
bool ListaDobleEnlazada::eliminar(int valor) {
    Nodo* temp = cabeza;
    while (temp) {
        if (temp->valor == valor) {
            if (temp->anterior) temp->anterior->siguiente = temp->siguiente;
            else cabeza = temp->siguiente;

            if (temp->siguiente) temp->siguiente->anterior = temp->anterior;
            else cola = temp->anterior;

            delete temp;
            return true;  // Retornar true si se eliminó el elemento
        }
        temp = temp->siguiente;
    }
    return false;  // Retornar false si no se encontró el elemento
}

// Mostrar la lista de inicio a fin
void ListaDobleEnlazada::mostrar() const {
    Nodo* temp = cabeza;
    while (temp) {
        cout << temp->valor << " ";
        temp = temp->siguiente;
    }
    cout << endl;
}
