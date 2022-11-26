#include <iostream>

int factorial(int);

int main() {

    int num = 3;   

    std::cout<< "Factorial de " <<num<< " = " << factorial(num) << '\n';

    system("pause");
    return 0;
}

int factorial(int num) {
    if (num == 0)                           // caso base
        num = 1;
    else                                    // caso general
        num = num * factorial(num - 1);
    //  num *= factorial(num - 1);

    return num;
}