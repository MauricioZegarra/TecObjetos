#include <iostream>
#include "ListaDobleEnlazada.cpp"

using namespace std;

// Función para mostrar el menú de opciones al usuario
void mostrarMenu() {
    cout << "\nMENU:\n";
    cout << "1. Insertar un elemento\n";
    cout << "2. Eliminar un elemento\n";
    cout << "3. Mostrar la lista\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    // Crear una lista doblemente enlazada vacía
    ListaDobleEnlazada lista;

    int opcion, valor;  // Variables para almacenar la opción del usuario y los valores a procesar

    // Ciclo que mantiene el menú activo hasta que el usuario decida salir (opción 4)
    do {
        mostrarMenu();  // Mostrar el menú de opciones
        cin >> opcion;  // Leer la opción ingresada por el usuario

        // Evaluar la opción seleccionada por el usuario
        switch (opcion) {
            case 1:
                // Opción para insertar un valor al final de la lista
                cout << "Ingrese el valor a insertar: ";
                cin >> valor;  // Leer el valor ingresado por el usuario
                lista.insertarFinal(valor);  // Insertar el valor en la lista
                cout << "Valor insertado." << endl;
                break;

            case 2:
                // Opción para eliminar un valor de la lista
                cout << "Ingrese el valor a eliminar: ";
                cin >> valor;  // Leer el valor que el usuario desea eliminar
                if (lista.eliminar(valor)) {  // Intentar eliminar el valor de la lista
                    cout << "Elemento eliminado." << endl;  // Mensaje si se eliminó el elemento
                } else {
                    cout << "Elemento no encontrado." << endl;  // Mensaje si no se encontró el elemento
                }
                break;

            case 3:
                // Opción para mostrar todos los elementos de la lista
                cout << "Elementos en la lista: ";
                lista.mostrar();  // Mostrar la lista completa
                break;

            case 4:
                // Opción para salir del programa
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                // Si el usuario ingresa una opción no válida
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 4);  // El ciclo continúa hasta que el usuario ingresa la opción 4 (Salir)

    return 0;  // Termina el programa
}
