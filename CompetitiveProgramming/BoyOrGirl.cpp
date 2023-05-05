#include "Shortcuts.hpp"

// 0 <= strlen <= 100
string checkNickGender(const string& nick) {

    unordered_map<int, char> last_chars;

    for (int i = 0; i < nick.length(); ++i) {
        if (last_chars.find(i) == last_chars.end()) {
            cout << last_chars[i] << endl;
        }
        else {
            last_chars.emplace(i, nick[i]);
        }
    }

    cout << last_chars.size() << endl;
    return (last_chars.size() % 2 == 0) ? "CHAT WITH HER!" : "IGNORE HIM!";
}

int main() {

    string case_1 = "wjmzbmr";      // YES 6c/d
    string case_2 = "xiaodao";      // NO  5c/d
    string case_3 = "sietekplus";   // YES 8c/d

    cout << checkNickGender(case_1) << endl;
    cout << checkNickGender(case_2) << endl;
    cout << checkNickGender(case_3) << endl;

    return 0;
}