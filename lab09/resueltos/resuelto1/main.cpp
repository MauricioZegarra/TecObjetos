
#include <iostream>
#include "FooManager.h"

using namespace std;

int main() {
    cout << "Patron Singleton" << endl;

    FooManager::Create();

    FooManager* pMyFoo1 = FooManager::GetInst();
    if (pMyFoo1 != nullptr) {
        cout << "Primera instancia, sample data: " << pMyFoo1->GetSampleData() << endl;
        cout << "Direccion de memoria: " << pMyFoo1 << endl;
    }

    FooManager* pMyFoo2 = FooManager::GetInst();
    if (pMyFoo2 != nullptr) {
        cout << "Segunda instancia (debería ser la misma), sample data: " << pMyFoo2->GetSampleData() << endl;
        cout << "Direccion de memoria: " << pMyFoo2 << endl;
    }

    // Limpieza de la instancia única
    FooManager::Destroy();

    return 0;
}
