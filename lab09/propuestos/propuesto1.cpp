
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>

// Clase Cuenta
class Cuenta {
public:
    enum TipoCuenta { AHORRO, JOVEN, PLUSS, EMPRESARIAL, TARJETA_CREDITO };

private:
    TipoCuenta tipo;
    double saldo;
    double interes;

public:
    Cuenta(TipoCuenta tipo, double saldoInicial, double interes) : tipo(tipo), saldo(saldoInicial), interes(interes) {}

    void aplicarInteres() {
        saldo += saldo * interes;
    }

    void depositar(double monto) {
        saldo += monto;
    }

    bool retirar(double monto) {
        if (saldo >= monto) {
            saldo -= monto;
            return true;
        }
        return false;
    }

    double obtenerSaldo() const {
        return saldo;
    }

    TipoCuenta obtenerTipo() const {
        return tipo;
    }

    std::string obtenerNombreTipo() const {
        switch (tipo) {
        case AHORRO: return "Ahorro";
        case JOVEN: return "Joven";
        case PLUSS: return "Pluss";
        case EMPRESARIAL: return "Empresarial";
        case TARJETA_CREDITO: return "Tarjeta de Credito";
        default: return "Desconocido";
        }
    }
};

// Clase Singleton para Repositorio de Cuentas
class RepositorioCuentas {
private:
    static std::unique_ptr<RepositorioCuentas> instancia;
    std::map<int, std::vector<Cuenta>> cuentasPorCliente;

    RepositorioCuentas() {}

public:
    // Prohibir copia y asignación
    RepositorioCuentas(const RepositorioCuentas&) = delete;
    RepositorioCuentas& operator=(const RepositorioCuentas&) = delete;

    static RepositorioCuentas& obtenerInstancia() {
        if (!instancia) {
            instancia = std::unique_ptr<RepositorioCuentas>(new RepositorioCuentas());
        }
        return *instancia;
    }

    void agregarCuenta(int clienteId, Cuenta cuenta) {
        cuentasPorCliente[clienteId].push_back(cuenta);
    }

    const std::vector<Cuenta>& obtenerCuentas(int clienteId) const {
        return cuentasPorCliente.at(clienteId);
    }

    void mostrarEstadoCuentas(int clienteId) const {
        if (cuentasPorCliente.find(clienteId) != cuentasPorCliente.end()) {
            const auto& cuentas = cuentasPorCliente.at(clienteId);
            std::cout << "Estado de cuentas para cliente " << clienteId << ":\n";
            for (const auto& cuenta : cuentas) {
                std::cout << "- Tipo: " << cuenta.obtenerNombreTipo() << ", Saldo: " << cuenta.obtenerSaldo() << "\n";
            }
        } else {
            std::cout << "El cliente no tiene cuentas registradas.\n";
        }
    }
};

std::unique_ptr<RepositorioCuentas> RepositorioCuentas::instancia = nullptr;

// Main para demostración
int main() {
    RepositorioCuentas& repositorio = RepositorioCuentas::obtenerInstancia();

    // Crear cuentas para el cliente 1
    repositorio.agregarCuenta(1, Cuenta(Cuenta::AHORRO, 1000, 0.005));
    repositorio.agregarCuenta(1, Cuenta(Cuenta::TARJETA_CREDITO, 5000, 0.15));

    // Crear cuentas para el cliente 2
    repositorio.agregarCuenta(2, Cuenta(Cuenta::EMPRESARIAL, 20000, 0.04));

    // Mostrar estado de cuentas
    repositorio.mostrarEstadoCuentas(1);
    repositorio.mostrarEstadoCuentas(2);

    return 0;
}
