#include <iostream>

int main() {
    int num;

    num = 20;
    int* dir_num = &num; // ej: dir_num = 0x61fe14

    std::cout << "Número: " << *dir_num << '\n';
    std::cout << "Dirección de memoria: " << dir_num << '\n';

    // int num = 20;
    // &num = 0x61f314
    // int* dir_num = 0x61fe14
    // *dir_num = 20

    return 0;
}