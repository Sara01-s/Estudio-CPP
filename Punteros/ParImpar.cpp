#include <iostream>

int main() {
    int numero;
    int *dir_num;

    std::cout<< "Digite un número: "; std::cin >> numero;

    dir_num = &numero; // guardando dirección de memoria de &numero en dir_num

    if (*dir_num % 2 == 0) { // ver si el número es impar o impar
        std::cout<< "El numero" << *dir_num << " es par." << '\n';
        std::cout<< "Direccion numero:" << dir_num << '\n';
    }
    else {
        std::cout<< "El numero" << *dir_num << " es impar." << '\n';
        std::cout<< "Direccion numero: " << dir_num << '\n';
    }

    return 0;
}