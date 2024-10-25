#include <iostream>
using namespace std;

class Persona {
public:
    virtual void habilidades() {
        cout << "Habilidades generales de una persona." << endl;
    }
};

class Nino : public Persona {  // Cambiado "Niño" a "Nino"
public:
    void habilidades() override {
        cout << "El niño juega." << endl;
    }
};

class Joven : public Persona {
public:
    void habilidades() override {
        cout << "El joven estudia." << endl;
    }
};

class Adulto : public Persona {
public:
    void habilidades() override {
        cout << "El adulto trabaja." << endl;
    }
};

int main() {
    Persona *p1 = new Nino();   // Cambiado "Niño" a "Nino"
    Persona *p2 = new Joven();
    Persona *p3 = new Adulto();
    
    p1->habilidades();
    p2->habilidades();
    p3->habilidades();
    
    delete p1;
    delete p2;
    delete p3;
    
    return 0;
}

