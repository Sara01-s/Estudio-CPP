#include <iostream>
#include "Punto.h"

void Punto::setX(int valorX) {
    _x = valorX;
}

void Punto::setY(int valorY) {
    _y = valorY;
}

int Punto::getX() {
    return _x;
}

int Punto::getY() {
    return _y;
}

void Punto::datos() {
    std::cout << "X: " << _x << " Y: " << _y << '\n';
    // Console.Write("X" + _x);
}