#include <iostream>
#include <conio.h>
#include "Punto.h"

void modificar(Punto &p, int x, int y) {
    p.setX(x);
    p.setY(y);
}

int main(int argc, char** argv) {

    // Objeto estático
    Punto p1(2, 1);
    // Punto p1 = new Punto(2, 1);

    std::cout << "El valor de X en p1 es: " << p1.getX() << '\n';

    // Objeto dinámico
    Punto* p2 = new Punto();

    p2->setX(5);
    p2->setY(8);

    std::cout << "El valor de X en p2 es: " << p2->getX() << '\n';
    std::cout << "El valor de Y en p2 es: " << p2->getY() << '\n';

    p1.~Punto(); // luego de usar el objeto podemos eleminarlo de la memoria manualmente
    delete p2;   // luego de usar el objeto dinámico, eliminamos usando delete


    Punto* p3 = new Punto();
    modificar(*p3, 10, 50);
    p3->datos();

    delete p3;

    getch();
    return 0;
 
}
