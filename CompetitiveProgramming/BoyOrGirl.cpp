#include "Shortcuts.hpp"

// 0 <= strlen <= 100
string checkNickGender(const string& nick) {
    int distinct_chars = 0;

    for (int i = 0; i < nick.length(); ++i) {
        for (int j = 0; j < nick.length(); ++j) {
            if (i != j) {
                if (nick[i] == nick[j]) {
                    ++distinct_chars;
                }
            }
        }
    }

    return (distinct_chars % 2 == 0) ? "CHAT WITH HER!" : "IGNORE HIM!";
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