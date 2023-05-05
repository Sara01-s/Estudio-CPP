#include <iostream>
#include "Shortcuts.hpp"

int main() {

    vi w(100);
    iota(w.begin(), w.end(), 1);
    int lastNum = 0;

    for (int i = 0; i < w.size(); ++i) {
        
        int melon_half = w[i] / 2;
        if (lastNum == melon_half) continue;
        cout << melon_half << ": ";

        if (melon_half % 2 == 0) {
            cout << "YES" << endl;
            lastNum = melon_half;
        }
        else {
            cout << "NO" << endl;
            lastNum = melon_half;
        }
    }

    return 0;
}



