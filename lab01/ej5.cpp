#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estructura que representa un producto
struct Producto {
    string nombre;
    double precio;

    // Constructor
    Producto(string n, double p) : nombre(n), precio(p) {}
};

// Estructura que simula un carrito de compras
struct Carrito {
    vector<Producto> productos;

    // Método para agregar producto
    void agregar(string nombre, double precio) {
        Producto nuevo_producto(nombre, precio);
        productos.push_back(nuevo_producto);
    }

    // Método para eliminar producto
    void eliminar(string nombre) {
        bool encontrado = false;
        for (int pos = 0; pos < productos.size(); ++pos) {
            if (productos[pos].nombre == nombre) {
                productos.erase(productos.begin() + pos);
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "Producto no encontrado.\n";
        }
    }

    // Método para mostrar los productos en el carrito
    void mostrar() {
        if (productos.empty()) {
            cout << "El carrito está vacío.\n";
        } else {
            cout << "Productos en el carrito:\n";
            for (int pos = 0; pos < productos.size(); ++pos) {
                cout << "- " << productos[pos].nombre << " (Precio: " << productos[pos].precio << ")\n";
            }
        }
    }

    // Método para calcular el total
    double calcular_total() {
        double total = 0;
        for (int pos = 0; pos < productos.size(); ++pos) {
            total += productos[pos].precio;
        }
        return total;
    }
};

// Estructura que simula una billetera electrónica
struct Billetera {
    double saldo;

    // Constructor
    Billetera(double s) : saldo(s) {}

    // Método para pagar una cantidad
    bool pagar(double monto) {
        if (saldo >= monto) {
            saldo -= monto;
            return true;
        }
        return false;
    }

    // Método para agregar saldo
    void agregar_saldo(double monto) {
        saldo += monto;
    }

    // Método para mostrar el saldo
    void mostrar_saldo() {
        cout << "Saldo: " << saldo << endl;
    }
};

int main() {
    Billetera mi_billetera(50);  // Saldo inicial de 50
    Carrito mi_carrito;

    char opcion;
    do {
        cout << "\n1. Agregar producto\n2. Eliminar producto\n3. Ver productos\n4. Pagar carrito\n5. Mostrar saldo\n6. Agregar saldo\n7. Salir\n\nElija una opción: ";
        cin >> opcion;
        cout << "\n";

        if (opcion == '1') {
            string nombre_producto;
            double precio_producto;
            cout << "Ingrese nombre del producto: ";
            cin >> nombre_producto;
            cout << "Ingrese precio del producto: ";
            cin >> precio_producto;
            mi_carrito.agregar(nombre_producto, precio_producto);
            mi_carrito.mostrar();
        }
        else if (opcion == '2') {
            mi_carrito.mostrar();
            string nombre_producto;
            cout << "Ingrese el producto a eliminar: ";
            cin >> nombre_producto;
            mi_carrito.eliminar(nombre_producto);
        }
        else if (opcion == '3') {
            mi_carrito.mostrar();
        }
        else if (opcion == '4') {
            double total = mi_carrito.calcular_total();

            if (mi_billetera.pagar(total)) {
                cout << "Pago realizado. Total: " << total << "\n";
                // Después de pagar, se vacía el carrito
                mi_carrito = Carrito();
            } else {
                cout << "Saldo insuficiente.\n";
            }
            mi_billetera.mostrar_saldo();
        }
        else if (opcion == '5') {
            mi_billetera.mostrar_saldo();
        }
        else if (opcion == '6') {
            double cantidad;
            cout << "Ingrese la cantidad de saldo a agregar: ";
            cin >> cantidad;
            mi_billetera.agregar_saldo(cantidad);
            mi_billetera.mostrar_saldo();
        }

    } while (opcion != '7');

    return 0;
}
