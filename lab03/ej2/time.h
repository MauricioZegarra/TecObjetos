#ifndef TIME_H
#define TIME_H

#include <memory>
using namespace std;  // Usamos el espacio de nombres estándar

class Time {
private:
    unique_ptr<int> hora;     // Puntero inteligente para la hora
    unique_ptr<int> minuto;   // Puntero inteligente para el minuto
    unique_ptr<int> segundo;  // Puntero inteligente para el segundo

public:
    Time(int h, int m, int s);  // Constructor que inicializa los valores
    void mostrarHora() const;   // Muestra la hora
};

#endif
