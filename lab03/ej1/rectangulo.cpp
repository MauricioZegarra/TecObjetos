#include "rectangulo.h"

Rectangulo::Rectangulo(double l, double a)
    : largo(make_unique<double>(l)), ancho(make_unique<double>(a)) {}  // Inicializa los punteros

double Rectangulo::area() const {
    return (*largo) * (*ancho);  // Calcula el área
}

double Rectangulo::perimetro() const {
    return 2 * (*largo + *ancho);  // Calcula el perímetro
}
