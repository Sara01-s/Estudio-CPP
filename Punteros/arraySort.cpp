#include <iostream>

void ordenar(int*, int);
void mostrarArray(int*, int);

int main() {
    int nums[] = {4, 2, 7, 8, 2, 1};
    int size = 6;

    mostrarArray(&nums[0], size);
    ordenar(&nums[0], size);
    std::cout<< "Ordenando..." << '\n';
    mostrarArray(&nums[0], size);

    return 0;
}

void ordenar(int* array, int size) {
    int aux;

    // ordenar arreglo usando bubble sort y punteros
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-1; j++) {
            if (*(array+j) > *(array + j + 1)) {
                
                aux = *(array+j);
                *(array+j) = *(array+j+1);
                *(array+j+1) = aux;
            }
        }
    }
} 

void mostrarArray(int* array, int size) {
    std::cout<<"Array: ";
    for (int i = 0; i < size; i++) {
        std::cout<< *(array+i); // lo mismo que array[i] :o
    }

    std::cout<<"\n";
}