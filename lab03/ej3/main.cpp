#include "ListaDoble.cpp"
#include <iostream>
using namespace std;  // Usamos el espacio de nombres estándar

int main() {
    ListaDoble lista;  // Creamos la lista

    lista.agregar(10);
    lista.agregar(20);
    lista.agregar(30);

    // Imprimir la lista desde el inicio y el final
    cout << "Lista desde adelante: ";
    lista.imprimirDesdeAdelante();

    cout << "Lista desde atrás: ";
    lista.imprimirDesdeAtras();

    return 0;
}
