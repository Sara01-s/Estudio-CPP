#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

typedef long long           ll;
typedef pair<int, int>      ii;
typedef vector<int>         vi;
typedef vector<ii>          vii;
#define INF                 1_000_000_000

int main() {
    int n {};
    cin >> n;
    int ans { 0 };

    for (int i = 0; i < n; ++i) {
        short a, b, c;
        cin >> a >> b >> c;
        if (a + b + c >= 2) {
            ++ans;
        }
    }

    cout << ans;
    return 0;
}