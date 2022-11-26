#include <iostream>

void intercambiar(float*, float*); // Declaración de función para usarla abajo del main

int main() {

    float num1 = 20.8, num2 = 7.6;

    std::cout<< "Primer numero: " << num1 << '\n';
    std::cout<< "Segundo numero: " << num2 << '\n';

    std::cout<< "--- Intercambio whooosh ---" << '\n';
    intercambiar(&num1, &num2);

    std::cout<< "Primer numero: " << num1 << '\n';
    std::cout<< "Segundo numero: " << num2 << '\n';

    return 0;
}

void intercambiar(float* dirNum1, float* dirNum2) {
    float valorNum1;

    // Intercambiar valores :O
    valorNum1 = *dirNum1;
    *dirNum1 = *dirNum2;
    *dirNum2 = valorNum1;
}