#ifndef RECTANGULO_H
#define RECTANGULO_H

#include <memory>
using namespace std;  // Usamos el espacio de nombres estándar

class Rectangulo {
private:
    unique_ptr<double> largo;  // Puntero inteligente para el largo
    unique_ptr<double> ancho;  // Puntero inteligente para el ancho

public:
    Rectangulo(double l, double a);  // Constructor que inicializa los valores
    double area() const;             // Calcula el área
    double perimetro() const;        // Calcula el perímetro
};

#endif
