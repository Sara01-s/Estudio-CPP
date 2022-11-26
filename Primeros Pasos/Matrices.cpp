#include <iostream>
#include <conio.h>

using namespace std;

int main() {

    int matriz3x3[3][3] = {{1,2,3}, 
                           {4,5,6}, 
                           {7,8,9}};
    
    cout << "Matriz completa" << endl;
    for (int i = 0; i < 3; i++) {
        for(int j = 0; i < 3; i++) {
            cout << matriz3x3[i][j];
        }

        cout << endl;
    }

    cout << "Diagonal principal" << endl;
    for (int i = 0; i < 3; i++) {
        for(int j = 0; i < 3; i++) {
            if (i == j) {
                cout << matriz3x3[i][j] << endl;
            }
        }

        cout << endl;
    }

    getch();
    return 0;
}