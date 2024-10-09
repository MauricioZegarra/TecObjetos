#include "time.h"
#include <iostream>
using namespace std;  // Usamos el espacio de nombres estándar

Time::Time(int h, int m, int s)
    : hora(make_unique<int>(h)), minuto(make_unique<int>(m)), segundo(make_unique<int>(s)) {}  // Inicializa los punteros

void Time::mostrarHora() const {
    // Imprime la hora en formato HH:MM:SS
    cout << *hora << ":" << *minuto << ":" << *segundo << endl;
}
