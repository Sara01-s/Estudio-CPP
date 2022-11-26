/*
Given a array of numbers representing the stock prices of a company in chronological order, 
write a function that calculates the maximum profit you could have made from buying and selling 
that stock once. You must buy before you can sell it.

For example, given [9, 11, 8, 5, 7, 10], 
you should return 5, since you could buy the stock at 5 dollars and sell it at 10 dollars.
*/                                                                                                                                                                                                    //xd

#include <iostream>

using namespace std;

int GetMinNumberPosition(int array[], int size) {
    int minNumber = INT_MAX;
    int posicion = -1;

    for (int i = 0; i < size; i++) {
        
        if (array[i] < minNumber) {
            minNumber = array[i];       // Valor de la posicion
            posicion = i;               // Poisción del valor
        }
    }

    return posicion;

    // int* -> array[0]
    // "int*++" -> *(&array++)
}

int GetMaxProfit(int array[], int arraySize) {
    // Lógica
    // Obtener posición del valor mínimo del array = VM
    int minNumberPos = GetMinNumberPosition(array, arraySize);
    // Todos los números delante de ese número pueden ser el mayor profit
    // Obtener valor máximo posible antes de que termine el array DESPUES de VM

    int mayorProfit = 0;

    while (array[minNumberPos] < arraySize) {
        // Obtener mayor número entre la posición del minNumber y el fin del array

    }

    // return valor maximo
    return 0;
}

int main(int argc, char** argv) {
    
    int _acciones[] = { 9, 11, 12, 10000000, 7, 10 };
    int _arraySize = 6;
    int _accionMenor = 0;

    cout<< "Mejor accion: " << GetMaxProfit(_acciones, _arraySize) << endl;

    return 0;
}