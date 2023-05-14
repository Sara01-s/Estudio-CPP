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

string abbreviateLongWord(string& s) {
    if (s.length() <= 10) {
        return s;
    }

    int new_length = s.length() - 2;

    return s[0] + to_string(new_length) + s[s.length() - 1];
}

int main() {
    int n{};
    cin >> n;

    //vector<string> answers(n);

    for(int i=0;i<n;i++){        
        string input{};
        cin >> input;
        cout << abbreviateLongWord(input) << '\n';
        //answers[i] = abbreviateLongWord(input);
    }



    return 0;
}