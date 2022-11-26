#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void escribir();

int main() {

    escribir();

    return 0;
}

void escribir() {
    ofstream archivo;
    string ruta = "C:\\Users\\Lenovo\\Desktop\\C#, C++ y JS\\Curso C++\\Archivos\\";
    string nombre;
    string frase;
    int opcion;

    cout<< "\t-| Creador de txt |-\n";
    cout<< "Escriba el nombre del archivo > ";
    getline(cin, nombre);

    archivo.open(ruta.append(nombre.append(".txt")).c_str(), ios::out);

    if (archivo.fail()) {
        cout<< "\nNo se pudo abrir el archivo.";
        exit(1);
    }

    system("cls");

    do {
        cout<< "\t_.: MENU :._\n";
        cout<< "1.: Escribir frase.\n";
        cout<< "2.: Salir.\n";
        cout<< "Opcion:  "; cin>> opcion;

        fflush(stdin); // limpiar buffer de la memoria
                       // es lo mismo que cin.clear(); cin.sync();

        switch(opcion) {
            case 1: cout<<"\nEscriba una frase > ";
                    getline(cin, frase);
                    archivo<< frase;

                    cout<< "> Frase incluida" << '\n';
                    system("pause");
                    break;
        }
        system("cls");

    } while (opcion != 2);

    archivo.close();
}