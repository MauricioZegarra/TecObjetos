
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Componente {
public:
    string nombre, color;

    Componente(const string& n, const string& c) : nombre(n), color(c) {}

    string descripcion() const {
        return nombre + " (Color: " + color + ")";
    }
};

class Automovil {
public:
    string modelo, motorizacion, pais;
    double precio;
    vector<Componente> componentes;

    void mostrar() const {
        cout << "Modelo: " << modelo << ", Motorización: " << motorizacion
             << ", País: " << pais << ", Precio: $" << precio << endl;
        cout << "Componentes seleccionados:" << endl;
        for (const auto& c : componentes) {
            cout << "- " << c.descripcion() << endl;
        }
    }
};

class IBuilder {
public:
    virtual void definirModelo(const string&) = 0;
    virtual void definirMotorizacion(const string&) = 0;
    virtual void definirPais(const string&) = 0;
    virtual void definirPrecio(double) = 0;
    virtual void agregarComponente(const string&, const string&) = 0;
    virtual Automovil obtenerAutomovil() = 0;
    virtual ~IBuilder() = default;
};

class BuilderEspecifico : public IBuilder {
    Automovil automovil;

public:
    void definirModelo(const string& modelo) override {
        automovil.modelo = modelo;
    }

    void definirMotorizacion(const string& motorizacion) override {
        automovil.motorizacion = motorizacion;
    }

    void definirPais(const string& pais) override {
        automovil.pais = pais;
    }

    void definirPrecio(double precio) override {
        automovil.precio = precio;
    }

    void agregarComponente(const string& nombre, const string& color) override {
        automovil.componentes.emplace_back(nombre, color);
    }

    Automovil obtenerAutomovil() override {
        return automovil;
    }
};

class Director {
    IBuilder* builder;

public:
    void setBuilder(IBuilder* b) {
        builder = b;
    }

    Automovil construir() {
        return builder->obtenerAutomovil();
    }
};

int mostrarMenu(const vector<string>& opciones) {
    for (size_t i = 0; i < opciones.size(); ++i) {
        cout << i + 1 << ". " << opciones[i] << endl;
    }
    cout << "Seleccione una opción: ";
    int seleccion;
    cin >> seleccion;
    return seleccion - 1;
}

int main() {
    BuilderEspecifico builder;
    Director director;

    director.setBuilder(&builder);

    vector<string> modelos = {"Sedan", "SUV", "Hatchback"};
    vector<string> motorizaciones = {"Gasolina", "Eléctrico", "Híbrido"};
    vector<string> paises = {"Japón", "Alemania", "EE.UU."};
    vector<string> componentes = {"Puertas", "Llantas", "Asientos", "Motor", "Espejos"};
    vector<string> colores = {"Negro", "Blanco", "Rojo", "Azul", "Gris"};

    cout << "\nSeleccione el modelo del automóvil:" << endl;
    int seleccion = mostrarMenu(modelos);
    builder.definirModelo(modelos[seleccion]);

    cout << "\nSeleccione la motorización:" << endl;
    seleccion = mostrarMenu(motorizaciones);
    builder.definirMotorizacion(motorizaciones[seleccion]);

    cout << "\nSeleccione el país de fabricación:" << endl;
    seleccion = mostrarMenu(paises);
    builder.definirPais(paises[seleccion]);

    double precio;
    cout << "\nIngrese el precio: ";
    cin >> precio;
    builder.definirPrecio(precio);

    while (true) {
        cout << "\nSeleccione un componente para agregar (o 0 para terminar):" << endl;
        seleccion = mostrarMenu(componentes);
        if (seleccion < 0 || seleccion >= componentes.size()) break;

        cout << "\nSeleccione el color del componente:" << endl;
        int seleccionColor = mostrarMenu(colores);

        builder.agregarComponente(componentes[seleccion], colores[seleccionColor]);
    }

    Automovil automovil = director.construir();
    cout << "\nResumen de su selección:\n" << endl;
    automovil.mostrar();

    return 0;
}
