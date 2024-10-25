#include <iostream>
using namespace std;

class Mamifero {
public:
    virtual void actividad() {
        cout << "El mamífero realiza una actividad general." << endl;
    }
};

class Perro : public Mamifero {
public:
    void actividad() override {
        cout << "El perro ladra." << endl;
    }
};

class Gato : public Mamifero {
public:
    void actividad() override {
        cout << "El gato maúlla." << endl;
    }
};

class Ballena : public Mamifero {
public:
    void actividad() override {
        cout << "La ballena nada." << endl;
    }
};

int main() {
    Mamifero *m1 = new Perro();
    Mamifero *m2 = new Gato();
    Mamifero *m3 = new Ballena();
    
    m1->actividad();
    m2->actividad();
    m3->actividad();
    
    delete m1;
    delete m2;
    delete m3;
    
    return 0;
}

