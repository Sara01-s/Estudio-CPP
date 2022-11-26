#include <iostream>

struct Persona {
    char nombre[30];
    int edad;
} persona, *dir_persona = &persona;

void pedirDatos(); // declaración función
void mostrarDatos(Persona*);

int main() {

    pedirDatos();
    mostrarDatos(dir_persona);


    return 0;
}

void pedirDatos() {
    std::cout<< "Digite su nombre: ";
    std::cin.getline(dir_persona->nombre, 30, '\n');
    
    std::cout<< "Digite su edad: ";
    std::cin>> dir_persona->edad;
}

void mostrarDatos(Persona* punteroPersona) {
    std::cout<< "Su nombre es: " << punteroPersona->nombre << '\n';
    std::cout<< "Su edad es: " << punteroPersona->edad << '\n';
}