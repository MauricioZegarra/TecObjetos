
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Cuenta {
protected:
    string titular;
    double saldo;

public:
    Cuenta(const string& titular, double saldo) : titular(titular), saldo(saldo) {}
    virtual ~Cuenta() {}
    virtual double calcularInteres() const = 0;
    virtual string obtenerTipo() const = 0;
    double obtenerSaldo() const { return saldo; }
    void depositar(double monto) { saldo += monto; }
    bool retirar(double monto) {
        if (monto > saldo) return false;
        saldo -= monto;
        return true;
    }
    string obtenerTitular() const { return titular; }
};

class CuentaAhorro : public Cuenta {
public:
    CuentaAhorro(const string& titular, double saldo) : Cuenta(titular, saldo) {}
    double calcularInteres() const override { return saldo * 0.0045; }
    string obtenerTipo() const override { return "Ahorro"; }
};

class CuentaJoven : public Cuenta {
public:
    CuentaJoven(const string& titular, double saldo) : Cuenta(titular, saldo) {}
    double calcularInteres() const override { return saldo * 0.0125; }
    string obtenerTipo() const override { return "Joven"; }
};

class CuentaPluss : public Cuenta {
public:
    CuentaPluss(const string& titular, double saldo) : Cuenta(titular, saldo) {}
    double calcularInteres() const override { return saldo * 0.0175; }
    string obtenerTipo() const override { return "Pluss"; }
};

class CuentaEmpresarial : public Cuenta {
public:
    CuentaEmpresarial(const string& titular, double saldo) : Cuenta(titular, saldo) {}
    double calcularInteres() const override { return saldo * 0.0225; }
    string obtenerTipo() const override { return "Empresarial"; }
};

class TarjetaCredito : public Cuenta {
public:
    TarjetaCredito(const string& titular, double saldo) : Cuenta(titular, saldo) {}
    double calcularInteres() const override { return saldo * 0.165; }
    string obtenerTipo() const override { return "Tarjeta de Credito"; }
};

class Cliente {
    string nombre;
    vector<Cuenta*> cuentas;

public:
    Cliente(const string& nombre) : nombre(nombre) {}
    ~Cliente() {
        for (auto cuenta : cuentas) delete cuenta;
    }
    void agregarCuenta(Cuenta* cuenta) { cuentas.push_back(cuenta); }
    string obtenerNombre() const { return nombre; }
    void mostrarCuentas() const {
        for (const auto& cuenta : cuentas) {
            cout << cuenta->obtenerTipo() << " - Titular: " << cuenta->obtenerTitular()
                 << ", Saldo: " << cuenta->obtenerSaldo() << endl;
        }
    }
    double calcularInteresGlobal() const {
        double interesTotal = 0;
        for (const auto& cuenta : cuentas) {
            interesTotal += cuenta->calcularInteres();
        }
        return interesTotal;
    }
};

void mostrarMenu() {
    cout << "\n1. Agregar cliente\n"
         << "2. Agregar cuenta a cliente\n"
         << "3. Mostrar cuentas de cliente\n"
         << "4. Calcular interes global de cliente\n"
         << "5. Salir\n"
         << "Ingrese una opcion: ";
}

int main() {
    vector<Cliente*> clientes;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        if (opcion == 1) {
            string nombre;
            cout << "Ingrese el nombre del cliente: ";
            cin >> nombre;
            clientes.push_back(new Cliente(nombre));
        } else if (opcion == 2) {
            string nombre;
            cout << "Ingrese el nombre del cliente: ";
            cin >> nombre;

            auto it = find_if(clientes.begin(), clientes.end(), [&](Cliente* c) {
                return c->obtenerNombre() == nombre;
            });

            if (it != clientes.end()) {
                string tipo;
                double saldo;
                cout << "Ingrese el tipo de cuenta (Ahorro, Joven, Pluss, Empresarial, Tarjeta): ";
                cin >> tipo;
                cout << "Ingrese el saldo inicial: ";
                cin >> saldo;

                if (tipo == "Ahorro")
                    (*it)->agregarCuenta(new CuentaAhorro(nombre, saldo));
                else if (tipo == "Joven")
                    (*it)->agregarCuenta(new CuentaJoven(nombre, saldo));
                else if (tipo == "Pluss")
                    (*it)->agregarCuenta(new CuentaPluss(nombre, saldo));
                else if (tipo == "Empresarial")
                    (*it)->agregarCuenta(new CuentaEmpresarial(nombre, saldo));
                else if (tipo == "Tarjeta")
                    (*it)->agregarCuenta(new TarjetaCredito(nombre, saldo));
            } else {
                cout << "Cliente no encontrado.\n";
            }
        } else if (opcion == 3) {
            string nombre;
            cout << "Ingrese el nombre del cliente: ";
            cin >> nombre;

            auto it = find_if(clientes.begin(), clientes.end(), [&](Cliente* c) {
                return c->obtenerNombre() == nombre;
            });

            if (it != clientes.end()) {
                (*it)->mostrarCuentas();
            } else {
                cout << "Cliente no encontrado.\n";
            }
        } else if (opcion == 4) {
            string nombre;
            cout << "Ingrese el nombre del cliente: ";
            cin >> nombre;

            auto it = find_if(clientes.begin(), clientes.end(), [&](Cliente* c) {
                return c->obtenerNombre() == nombre;
            });

            if (it != clientes.end()) {
                cout << "Interes global: " << (*it)->calcularInteresGlobal() << endl;
            } else {
                cout << "Cliente no encontrado.\n";
            }
        }

    } while (opcion != 5);

    for (auto cliente : clientes) delete cliente;
    return 0;
}
