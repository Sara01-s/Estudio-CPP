#include <iostream>

int fibonacci(int);

int main() {
    int nElementos;

    do {
        std::cout<< "Digite numero de elementos: "; 
        std::cin>> nElementos;
    } while(nElementos <= 0);

    std::cout<<"\nSerie fibonacci: ";

    for (int i = 0; i < nElementos; i++) {
        std::cout<< fibonacci(i) << " - ";
    }

    return 0;
}

int fibonacci(int n) {
    if (n < 2) {
        return n;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}