#include <iostream>
using namespace std;

int main(int argc, char** argv) {

    int numero1 = 0;
    int numero2 = 0;
    string tipoExcepcion = "";

    cout << "Numero 1: "; cin >> numero1;
    cout << "Numero2: "; cin >> numero2;
    
    try {
        if (numero2 == 0) {
            tipoExcepcion = "El numero 2 no puede ser 0";
            throw tipoExcepcion;
        }
    }
    catch (const string& error) {
        cout << "Error: " << tipoExcepcion << endl;
    }

    int resultadoDivision = numero1 / numero2;

    cout << resultadoDivision << endl;

    return 0;
}