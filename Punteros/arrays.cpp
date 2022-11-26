#include <iostream>

int main() {

    int array[] = {1, 2, 3, 4, 5};
    int* dir_array;

    dir_array = &array[0];
    // puede simplificarse como:
    // dir_array = array;

    for (int i = 0; i < 5; i++) {
        // std::cout<< "Elemento del array["<<i<<"]: " << *dir_array++ << '\n';
        std::cout<< "Direccion memoria: " << array[i] << " es: " << dir_array++ << '\n';  
    }


    return 0;
}