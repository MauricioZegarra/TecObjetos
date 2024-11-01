#include <iostream>
#include <string>

template <typename T>
class Nodo {
public:
    T dato;
    Nodo* siguiente;

    Nodo(T valor) : dato(valor), siguiente(nullptr) {}
};

template <typename T>
class ListaEnlazada {
private:
    Nodo<T>* cabeza;

public:
    ListaEnlazada() : cabeza(nullptr) {}

    ~ListaEnlazada() {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            Nodo<T>* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }

    void agregar(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
        } else {
            Nodo<T>* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
    }

    void imprimir() const {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            std::cout << actual->dato;
            if (actual->siguiente != nullptr) {
                std::cout << " -> ";
            }
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Ejemplo con una secuencia de edades (enteros)
    ListaEnlazada<int> listaEdades;
    listaEdades.agregar(25);
    listaEdades.agregar(30);
    listaEdades.agregar(22);
    std::cout << "Secuencia de edades: ";
    listaEdades.imprimir();

    // Ejemplo con una secuencia de palabras (cadenas de texto)
    ListaEnlazada<std::string> listaPalabras;
    listaPalabras.agregar("Hola");
    listaPalabras.agregar("Mundo");
    listaPalabras.agregar("C++");
    std::cout << "Secuencia de palabras: ";
    listaPalabras.imprimir();

    return 0;
}
