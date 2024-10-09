#include "time.cpp"
#include <memory>
using namespace std;  // Usamos el espacio de nombres estándar

int main() {
    // Creamos un objeto Time en memoria dinámica usando un puntero inteligente
    unique_ptr<Time> t = make_unique<Time>(10, 30, 45);

    t->mostrarHora();  // Muestra la hora

    return 0;
}
