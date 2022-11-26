#include <iostream>
using namespace std;

int _numero1;
int _numero2;
int _resultadoSuma;


int main() {

    cout << "Ingrese primer número a sumar" << endl;
    cin >> _numero1;

    cout << "Ingrese segundo número a sumar" << endl;
    cin >> _numero2;

    _resultadoSuma = _numero1 + _numero2;
    
    cout << "Resultado suma: " << _resultadoSuma << endl;

    return 0;
}