#include <iostream>

// declaración de función
int encontrarMax(int*, int);


int main() {
    const int nElementos = 5;
    int numeros[] = {3, 5, 2, 8, 1};

    std::cout<< 
        "El mayor elemento es: " << encontrarMax(&numeros[0], nElementos) << '\n';

    return 0;
}

int encontrarMax(int* dir_array, int size) {
    int max = 0;

    for(int i = 0; i < size; i++) {
        if (*(dir_array + i) > max) {
            max = *(dir_array + i);
        }
    }

    return max;
}