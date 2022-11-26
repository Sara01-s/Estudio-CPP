#include <iostream>

void nuevoValor(int&, int&);

int main() {
    int num1, num2;

    std::cout<< "Digite 2 numeros: ";
    std::cin>> num1 >> num2;

    nuevoValor(num1, num2);

    std::cout<< "El nuevo valor del primer numero es: " << num1 << '\n';
    std::cout<< "El nuevo valor del segundo numero es: " << num2 << '\n';

    system("pause");
    return 0;
}

void nuevoValor(int& xnum, int& ynum) {
    std::cout<< "El valor del primer numero es: " << xnum << '\n';
    std::cout<< "El valor del segundo numero es: " << ynum << '\n';

    xnum = 20;
    ynum = 40;
}