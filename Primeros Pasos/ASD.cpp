#include <iostream>

void funcion(int& variable) {

    variable = 3;
}

int main() {

    int timer = 0;
    funcion(timer);

    return 0;
}