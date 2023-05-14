#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int x {};
    int ans { 0 };

    cin >> x;

    for (int i = 0; i <= x; ++i) {
        string op {};
        cin >> op;

        transform(op.begin(), op.end(), op.begin(), ::tolower);

        if (op.compare("x++") == 0 || op.compare("++x") == 0) {
            ans++;
        }
        else if (op.compare("x--") == 0 || op.compare("--x") == 0) {
            ans--;
        }
    }

    cout << ans;

    return 0;
}