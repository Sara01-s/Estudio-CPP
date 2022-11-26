#include <iostream>

using namespace std;

int main() {

    int numero = 24;
    int* punteroNumero;

    punteroNumero = &numero;

    cout<< "Dirección número: " << &numero << endl;
    cout<< "Valor número: " << numero << endl;

    return 0;
}