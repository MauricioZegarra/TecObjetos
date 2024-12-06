
#include <iostream>
#include <string>

// Declaración previa de clases necesarias
class AbstractProductoA; // Declaración anticipada de AbstractProductoA
class AbstractProductoB; // Declaración anticipada de AbstractProductoB

// Clase AbstractFactory
class AbstractFactory {
public:
    virtual AbstractProductoA* CrearProductoA() const = 0;
    virtual AbstractProductoB* CrearProductoB() const = 0;
    virtual ~AbstractFactory() {}
};

// Clase AbstractProductoA
class AbstractProductoA {
public:
    virtual ~AbstractProductoA() {}
    virtual std::string Funcion1_A() const = 0;
};

// Clases derivadas de AbstractProductoA
class CProductoA1 : public AbstractProductoA {
public:
    std::string Funcion1_A() const override {
        return "Producto A1.";
    }
};

class CProductoA2 : public AbstractProductoA {
public:
    std::string Funcion1_A() const override {
        return "Producto A2.";
    }
};

// Clase AbstractProductoB
class AbstractProductoB {
public:
    virtual ~AbstractProductoB() {}
    virtual std::string Funcion1_B() const = 0;
    virtual std::string Funcion2_B(const AbstractProductoA& colaborador) const = 0;
};

// Clases derivadas de AbstractProductoB
class CProductoB1 : public AbstractProductoB {
public:
    std::string Funcion1_B() const override {
        return "Producto B1.";
    }

    std::string Funcion2_B(const AbstractProductoA& colaborador) const override {
        const std::string result = colaborador.Funcion1_A();
        return "B1 con ayuda de " + result;
    }
};

class CProductoB2 : public AbstractProductoB {
public:
    std::string Funcion1_B() const override {
        return "Producto B2.";
    }

    std::string Funcion2_B(const AbstractProductoA& colaborador) const override {
        const std::string result = colaborador.Funcion1_A();
        return "B2 con ayuda de " + result;
    }
};

// Clases Factory
class CFactory1 : public AbstractFactory {
public:
    AbstractProductoA* CrearProductoA() const override {
        return new CProductoA1();
    }

    AbstractProductoB* CrearProductoB() const override {
        return new CProductoB1();
    }
};

class CFactory2 : public AbstractFactory {
public:
    AbstractProductoA* CrearProductoA() const override {
        return new CProductoA2();
    }

    AbstractProductoB* CrearProductoB() const override {
        return new CProductoB2();
    }
};

// Función Cliente
void Cliente(const AbstractFactory& f) {
    const AbstractProductoA* producto_a = f.CrearProductoA();
    const AbstractProductoB* producto_b = f.CrearProductoB();
    std::cout << producto_b->Funcion1_B() << "\n";
    std::cout << producto_b->Funcion2_B(*producto_a) << std::endl;
    delete producto_a;
    delete producto_b;
}

// Función principal
int main() {
    std::cout << "Cliente: Tipo 1\n";
    CFactory1 f1 = CFactory1();
    Cliente(f1);
    std::cout << std::endl;

    std::cout << "Cliente: Tipo 2\n";
    CFactory2 f2 = CFactory2();
    Cliente(f2);
    return 0;
}
