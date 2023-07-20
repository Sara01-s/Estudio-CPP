#include <iostream>
#include <array>
using namespace std;

int main() {

    array<array<int, 5>, 5> matrix { 0 };

    for (int i = 0; i < matrix.size(); ++i) {

        matrix[i][i] = i;

    }

    for (int i = 0; i < matrix.size(); ++i) {

        cout << matrix[i][0];

    }
    

    return 0;
}