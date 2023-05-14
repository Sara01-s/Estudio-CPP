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

// 0 <= strlen <= 100
string checkNickGender(const string& nick) {
    unordered_map<char, bool> last_chars{};
    // numero par de caracteres unicos => mujer
    for (int i = 0; i < nick.length(); ++i) {
        if (last_chars.find(i) != last_chars.end()) {
            // se encontro el caracter
            // hacemos nada
        } else {
            char newchar = nick[i];
            // no se encontro, por lo tanto, define un caracter unico, se agrega
            last_chars[newchar] = true;
        }
    }
    return (last_chars.size() % 2 == 0) ? "CHAT WITH HER!" : "IGNORE HIM!";
}

int main(void) {
    string input{};
    cin >> input;
    cout << checkNickGender(input);

    return 0;
}