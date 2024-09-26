#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Estructura para almacenar los datos de una persona
struct Persona {
    int edad;
    int grado_instruccion;
};

// Función para generar una edad aleatoria
int generar_edad() {
    return rand() % 66 + 15;  // Edad entre 15 y 80
}

// Función para generar un grado de instrucción aleatorio
int generar_grado() {
    return rand() % 3 + 1;  // Grado de instrucción entre 1 y 3
}

// Función para calcular el promedio de edades
double promedio_edades(vector<Persona>& personas) {
    int suma = 0;
    for (const Persona& p : personas) {
        suma += p.edad;
    }
    return (suma) / personas.size();
}

// Función para encontrar la mayor edad
int mayor_edad(vector<Persona>& personas) {
    int mayor = personas[0].edad;
    for (const Persona& p : personas) {
        if (p.edad > mayor) {
            mayor = p.edad;
        }
    }
    return mayor;
}

// Función para contar personas según el grado de instrucción
void contar_grados(vector<Persona>& personas, int& primaria, int& secundaria, int& superior) {
    primaria = secundaria = superior = 0;
    for (Persona& p : personas) {
        if (p.grado_instruccion == 1) {
            primaria++;
        }
        else if (p.grado_instruccion == 2) {
            secundaria++;
        }
        else {
            superior++;        
        }
    }
}

int main() {
    srand(time(0));  // Inicializar el generador de números aleatorios

    char next; //Variable para volver a simular

    do {
        int N;
        cout << "\nIngrese el número de personas: ";
        cin >> N;
    
        vector<Persona> personas(N);
    
        // Generar datos para cada persona
        for (int i = 0; i < N; ++i) {
            personas[i].edad = generar_edad();
            personas[i].grado_instruccion = generar_grado();
        }
    
        // Calcular el promedio de edades
        double promedio = promedio_edades(personas);
        cout << "Promedio de edades: " << promedio << endl;
    
        // Encontrar la mayor edad
        int mayor = mayor_edad(personas);
        cout << "La mayor edad es: " << mayor << endl;
    
        // Contar personas por grado de instrucción
        int primaria, secundaria, superior;
        contar_grados(personas, primaria, secundaria, superior);
    
        cout << "Personas con primaria: " << primaria << endl;
        cout << "Personas con secundaria: " << secundaria << endl;
        cout << "Personas con superior: " << superior << endl;

        cout << "\n¿Volver a simular? (S/N) -> ";
        cin >> next;
    }
    while (next == 'S');

    return 0;
}
