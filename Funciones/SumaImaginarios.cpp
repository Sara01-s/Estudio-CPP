#include <iostream>
#include <string.h>

struct Complejo {
    float real;
    float imaginaria;

} z1, z2;

void pedirDatos();
Complejo suma(Complejo, Complejo);
void mostrarComplejo(Complejo);

int main() {

    void pedirDatos();

    Complejo numComplejo = suma(z1, z2);

    mostrarComplejo(numComplejo);

    system("pause");
    return 0;
}

void pedirDatos() {
    std::cout<< "Digite datos numero complejo: " << '\n';
    std::cout<< "Parte real: "; 
    std::cin>> z1.real;
    std::cout<< "Parte imaginaria: "; 
    std::cin>> z1.imaginaria;

    std::cout<< "Digite datos segundo numero complejo: " << '\n';
    std::cout<< "Parte real: "; 
    std::cin>> z2.real;
    std::cout<< "Parte imaginaria: "; 
    std::cin>> z2.imaginaria;
}

Complejo suma(Complejo c1, Complejo c2) {
    c1.real += c2.real;
    c1.imaginaria += c2.imaginaria;

    return c1;
}

void mostrarComplejo(Complejo c) {
    std::cout<< "Resultado suma: " << c.real << " , " << c.imaginaria << '\n';
}

/* Ejemplo:

    z1 = 5 - 3i
    z2 = -4 + 2i

    z1 + z2 = (5 - 3i) + (-4 + 2i)
            = 5 - 3i - 4 - 2i
            = 1 - i
            
*/