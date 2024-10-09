#include "ListaDoble.h"
#include <iostream>
using namespace std;  // Usamos el espacio de nombres estándar

ListaDoble::ListaDoble() : cabeza(nullptr), cola(nullptr) {}  // Inicializa la lista vacía

ListaDoble::~ListaDoble() {
    // Liberar memoria de todos los nodos
    Nodo* actual = cabeza;
    while (actual) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
}

void ListaDoble::agregar(int valor) {
    Nodo* nuevo = new Nodo(valor);  // Crear nuevo nodo
    if (!cabeza) {  // Si la lista está vacía
        cabeza = cola = nuevo;
    } else {
        cola->siguiente = nuevo;
        nuevo->anterior = cola;
        cola = nuevo;
    }
}

void ListaDoble::imprimirDesdeAdelante() const {
    Nodo* actual = cabeza;
    while (actual) {  // Recorre la lista desde el inicio
        cout << actual->valor << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

void ListaDoble::imprimirDesdeAtras() const {
    Nodo* actual = cola;
    while (actual) {  // Recorre la lista desde el final
        cout << actual->valor << " ";
        actual = actual->anterior;
    }
    cout << endl;
}

Nodo* ListaDoble::buscarDesdeAdelante(int valor) const {
    Nodo* actual = cabeza;
    while (actual && actual->valor != valor) {
        actual = actual->siguiente;
    }
    return actual;  // Retorna el nodo encontrado o nullptr
}

Nodo* ListaDoble::buscarDesdeAtras(int valor) const {
    Nodo* actual = cola;
    while (actual && actual->valor != valor) {
        actual = actual->anterior;
    }
    return actual;  // Retorna el nodo encontrado o nullptr
}
