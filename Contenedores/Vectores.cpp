#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

    vector<int> _numeros; // arreglo de enteros dinámico

    _numeros.push_back(5); // Agrega elementos al final del arreglo
    _numeros.push_back(10);
    _numeros.push_back(1);
    _numeros.push_back(15);
    _numeros.push_back(20);

    // Imprimir elementos del vector
    for (int i = 0; i < _numeros.size(); i++)
        cout << _numeros[i] << "|";

    // quitar el último elemento del vector
    _numeros.pop_back(); cout << endl;

    for (int i = 0; i < _numeros.size(); i++)
        cout << _numeros[i] << "|";

    // borrar rango de números
    _numeros.erase(_numeros.begin() + 1, _numeros.begin() + 3); cout << endl;

    for (int i = 0; i < _numeros.size(); i++)
        cout << _numeros[i] << "|";
    
    

    return 0;
}