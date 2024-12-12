#include <iostream>
#include <string>
#include <map>
#include <memory>

// Clase abstracta que define el prototipo
class Planta {
protected:
    std::string nombre;
    std::string tipo;
    std::string cuidados;

public:
    Planta(const std::string& nombre, const std::string& tipo, const std::string& cuidados)
        : nombre(nombre), tipo(tipo), cuidados(cuidados) {}

    virtual ~Planta() {}

    virtual std::unique_ptr<Planta> clonar() const = 0;

    void mostrarInformacion() const {
        std::cout << "Planta: " << nombre << ", Tipo: " << tipo << ", Cuidados: " << cuidados << "\n";
    }
};

// Clase concreta Trepadora
class Trepadora : public Planta {
public:
    Trepadora(const std::string& nombre, const std::string& cuidados)
        : Planta(nombre, "Trepadora", cuidados) {}

    std::unique_ptr<Planta> clonar() const override {
        return std::make_unique<Trepadora>(*this);
    }
};

// Clase concreta Arbol Normal
class ArbolNormal : public Planta {
public:
    ArbolNormal(const std::string& nombre, const std::string& cuidados)
        : Planta(nombre, "Arbol Normal", cuidados) {}

    std::unique_ptr<Planta> clonar() const override {
        return std::make_unique<ArbolNormal>(*this);
    }
};

// Clase concreta Ornamental
class Ornamental : public Planta {
public:
    Ornamental(const std::string& nombre, const std::string& cuidados)
        : Planta(nombre, "Ornamental", cuidados) {}

    std::unique_ptr<Planta> clonar() const override {
        return std::make_unique<Ornamental>(*this);
    }
};

// Clase concreta Bonsai
class Bonsai : public Planta {
public:
    Bonsai(const std::string& nombre, const std::string& cuidados)
        : Planta(nombre, "Bonsai", cuidados) {}

    std::unique_ptr<Planta> clonar() const override {
        return std::make_unique<Bonsai>(*this);
    }
};

// Repositorio de prototipos
class RepositorioPlantas {
private:
    std::map<std::string, std::unique_ptr<Planta>> prototipos;

public:
    void agregarPrototipo(const std::string& clave, std::unique_ptr<Planta> planta) {
        prototipos[clave] = std::move(planta);
    }

    std::unique_ptr<Planta> crearPlanta(const std::string& clave) {
        if (prototipos.find(clave) != prototipos.end()) {
            return prototipos[clave]->clonar();
        }
        return nullptr;
    }
};

// Main para demostrar funcionalidad
int main() {
    RepositorioPlantas repositorio;

    // Crear y agregar prototipos
    repositorio.agregarPrototipo("trepadora", std::make_unique<Trepadora>("Jazmin", "Riego frecuente"));
    repositorio.agregarPrototipo("arbol", std::make_unique<ArbolNormal>("Roble", "Riego moderado"));
    repositorio.agregarPrototipo("ornamental", std::make_unique<Ornamental>("Helecho", "Ambiente humedo"));
    repositorio.agregarPrototipo("bonsai", std::make_unique<Bonsai>("Pino", "Podas regulares"));

    // Crear nuevas plantas a partir de prototipos
    auto planta1 = repositorio.crearPlanta("trepadora");
    auto planta2 = repositorio.crearPlanta("arbol");
    auto planta3 = repositorio.crearPlanta("bonsai");

    // Mostrar informacion de las plantas creadas
    if (planta1) planta1->mostrarInformacion();
    if (planta2) planta2->mostrarInformacion();
    if (planta3) planta3->mostrarInformacion();

    return 0;
}
