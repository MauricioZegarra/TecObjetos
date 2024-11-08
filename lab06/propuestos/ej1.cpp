#include <iostream>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Nodo {
    int valor;
    Nodo* siguiente;
    Nodo(int v) : valor(v), siguiente(nullptr) {}
};

class ListaEnlazada {
private:
    Nodo* cabeza;
    mutex mtx;

public:
    ListaEnlazada() : cabeza(nullptr) {}

    // Inserta un nuevo nodo al principio de la lista
    void insertar(int valor) {
        lock_guard<mutex> lock(mtx);
        Nodo* nuevo = new Nodo(valor);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
        cout << "Insertando: " << valor << endl;
    }

    // Elimina un nodo con el valor especificado
    void eliminar(int valor) {
        lock_guard<mutex> lock(mtx);
        Nodo* actual = cabeza;
        Nodo* anterior = nullptr;
        while (actual != nullptr && actual->valor != valor) {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (actual == nullptr) {
            cout << "No se eliminó " << valor << endl;
        } else {
            if (anterior == nullptr) {
                cabeza = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual;
            cout << "Eliminando: " << valor << endl;
        }
    }

    // Busca un nodo con el valor especificado
    bool buscar(int valor) {
        lock_guard<mutex> lock(mtx);
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            if (actual->valor == valor) {
                cout << "Buscado: " << valor << " (encontrado)" << endl;
                return true;
            }
            actual = actual->siguiente;
        }
        cout << "No encontrado: " << valor << endl;
        return false;
    }

    // Modifica un nodo con el valor especificado
    void modificar(int valor, int nuevoValor) {
        lock_guard<mutex> lock(mtx);
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            if (actual->valor == valor) {
                cout << "Modificando " << valor << " a " << nuevoValor << endl;
                actual->valor = nuevoValor;
                return;
            }
            actual = actual->siguiente;
        }
        cout << "No se encontró " << valor << " para modificar" << endl;
    }

    // Imprime todos los elementos en la lista
    void imprimirLista() {
        lock_guard<mutex> lock(mtx);
        Nodo* actual = cabeza;
        cout << "Lista actual: ";
        while (actual != nullptr) {
            cout << actual->valor << " -> ";
            actual = actual->siguiente;
        }
        cout << "NULL" << endl;
    }
};

// Función para insertar valores aleatorios
void insertarValores(ListaEnlazada& lista) {
    for (int i = 0; i < 10; ++i) {
        int valor = rand() % 100;
        lista.insertar(valor);
    }
}

// Función para modificar valores aleatorios
void modificarValores(ListaEnlazada& lista) {
    for (int i = 0; i < 5; ++i) {
        int valor = rand() % 100;
        int nuevoValor = valor + rand() % 10;
        lista.modificar(valor, nuevoValor);
    }
}

// Función para buscar valores aleatorios
void buscarValores(ListaEnlazada& lista) {
    for (int i = 0; i < 5; ++i) {
        int valor = rand() % 100;
        lista.buscar(valor);
    }
}

// Función para eliminar valores aleatorios
void eliminarValores(ListaEnlazada& lista) {
    for (int i = 0; i < 5; ++i) {
        int valor = rand() % 100;
        lista.eliminar(valor);
    }
}

int main() {
    srand(time(0));
    ListaEnlazada lista;

    // Inserción de valores
    cout << "----- Inicio: Inserción de valores -----" << endl;
    insertarValores(lista);
    lista.imprimirLista();

    // Modificación de valores
    cout << "----- Modificación de valores -----" << endl;
    modificarValores(lista);
    lista.imprimirLista();

    // Primera búsqueda de valores
    cout << "----- Primera búsqueda de valores -----" << endl;
    buscarValores(lista);

    // Eliminación de valores
    cout << "----- Eliminación de valores -----" << endl;
    eliminarValores(lista);
    lista.imprimirLista();

    // Segunda búsqueda de valores
    cout << "----- Segunda búsqueda de valores -----" << endl;
    buscarValores(lista);

    return 0;
}

