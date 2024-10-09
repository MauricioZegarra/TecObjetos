#include <iostream>
#include "rectangulo.cpp"
using namespace std;  // Usamos el espacio de nombres estándar

int main() {
    // Creamos un objeto Rectángulo en memoria dinámica usando un puntero inteligente
    unique_ptr<Rectangulo> rect = make_unique<Rectangulo>(5.0, 3.0);

    cout << "Área: " << rect->area() << endl;          // Imprime el área
    cout << "Perímetro: " << rect->perimetro() << endl;  // Imprime el perímetro

    return 0;
}
