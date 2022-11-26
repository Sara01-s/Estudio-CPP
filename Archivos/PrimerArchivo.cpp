#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void escribir();

int main() {

    escribir();

    system("pause");
    return 0;
}

void escribir() {
    ofstream archivo; // output file stream
    string nombreArchivo;
    string frase;

    cout<< "Especifique nombre del archivo: ";
    getline(cin, nombreArchivo);

    archivo.open(nombreArchivo.c_str(), ios::out); // abrir archivo (como no existe lo va a crear)

    if (archivo.fail()) {
        cout<<",No se pudo abrir el archivo\n";
        exit(1);
    }

    cout<< "Escriba el texto del archivo: ";
    getline(cin, frase);

    archivo<< frase;

    archivo.close();
}