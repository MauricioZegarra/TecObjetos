#include <iostream>
using namespace std;

template <class T>
class Pila {
private:
    int maxSize;
    int topIndex;
    T* stackArray;

public:
    // Constructor para inicializar la pila con un tamaño máximo
    Pila(int size) : maxSize(size), topIndex(-1) {
        stackArray = new T[maxSize];
    }

    // Destructor para liberar memoria
    ~Pila() {
        delete[] stackArray;
    }

    // Método para insertar un elemento en la pila
    bool push(T value) {
        if (topIndex >= maxSize - 1) {
            cout << "La pila está llena. No se puede insertar " << value << "." << endl;
            return false;
        }
        stackArray[++topIndex] = value;
        return true;
    }

    // Método para extraer un elemento de la pila
    bool pop() {
        if (topIndex < 0) {
            cout << "La pila está vacía. No se puede extraer elementos." << endl;
            return false;
        }
        --topIndex;
        return true;
    }

    // Método para ver el elemento en la cima de la pila
    T top() const {
        if (topIndex < 0) {
            cout << "La pila está vacía." << endl;
            return T(); // Devuelve el valor predeterminado de T
        }
        return stackArray[topIndex];
    }

    // Método para verificar si la pila está vacía
    bool isEmpty() const {
        return topIndex < 0;
    }

    // Método para verificar si la pila está llena
    bool isFull() const {
        return topIndex >= maxSize - 1;
    }
};

int main() {
    // Pila de enteros
    Pila<int> pilaInt(5);
    pilaInt.push(10);
    pilaInt.push(20);
    cout << "Cima de pilaInt: " << pilaInt.top() << endl;
    pilaInt.pop();
    cout << "Cima de pilaInt después de pop: " << pilaInt.top() << endl;

    // Pila de caracteres
    Pila<char> pilaChar(3);
    pilaChar.push('A');
    pilaChar.push('B');
    cout << "Cima de pilaChar: " << pilaChar.top() << endl;
    pilaChar.pop();
    cout << "Cima de pilaChar después de pop: " << pilaChar.top() << endl;

    return 0;
}

