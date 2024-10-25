#include <iostream>
using namespace std;

int main() {
    auto suma = [](int valor) { return valor + 3; };
    
    int numero = 5;
    cout << "Resultado: " << suma(numero) << endl;
    
    return 0;
}
