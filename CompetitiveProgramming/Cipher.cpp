#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

string decryptMessage(const string& message, const string& freqLang);

int main() {

    const string FREQ_LANG = "TEOAISRHNUCMDLGWFPYKJBVQX";
    const string MESSAGE = "Bgc-bfufb tegaedppqna ql aggv zge xof tegaedppfe'l lgjb. "
                            "\nXof adpf vflqanfe logjbvn'x hf pdwqna d cgebv qn coqro xof tbdkfe ql mjlx d lpdbb tdex. Xof tbdkfe QL XOF HGLL; qx'l kgje vjxk xg fnxfexdqn oqp ge ofe."
                            "\nZgrjl ql d pdxxfe gz vfrqvqna codx xoqnal kgj def ngx agqna xg vg."
                            "\nXof rglx gz dvvqna d zfdxjef qln'x mjlx xof xqpf qx xdwfl xg rgvf qx. Xof rglx dblg qnrbjvfl xof dvvqxqgn gz dn ghlxdrbf xg zjxjef fstdnlqgn. Xof xeqrw ql xg tqrw xof zfdxjefl xodx vgn'x zqaox fdro gxofe. - Mgon Rdepdrw."
                            "\n(ccc.adpdljxed.rgp/uqfc/nfcl/234346?utkjpvbjr)"
                            "\n(ccc.hedqnkijgxf.rgp/ijgxfl/djxogel/m/mgon_rdepdrw.oxpb)";


    cout << decryptMessage(MESSAGE, FREQ_LANG);

    return 0;
}

string decryptMessage(const string& message, const string& freq_Lang) {
    
    string result {};
    unordered_map<char, int> freq_map {};

    for (size_t ch = 0; ch < message.length(); ch++) {
        
        char c = static_cast<char>(tolower(message[ch]));

        if (!('a' <= c && c <= 'z'))
            continue; // Skip chars who are not in [a-z] range.

        
        if (freq_map.find(c) != freq_map.end()) // char already found
            freq_map[c]++;
        else                             // new char found, map it
            freq_map.insert({c, 1});
    }

    vector<char> sortedChars {};
    for (const auto kv : freq_map) {
        sortedChars.push_back(kv.first); // Fill the vector with unsorted keys
    }

    sort(sortedChars.begin(), sortedChars.end(), [&freq_map](char i, char j) {
        return freq_map[i] > freq_map[j];
    });

    unordered_map<char, char> decryptMap {};

    for (int i = 0; i < sortedChars.size(); i++) {
        decryptMap[sortedChars[i]] = freq_Lang[i]; // sort[i] -> lang[i]
    }

    for (int i = 0; i < message.length(); i++) {
        char charToDecrypt = tolower(message[i]);

        if (decryptMap.find(charToDecrypt) == decryptMap.end()) {
            result += charToDecrypt;
            continue; // char doesn't need to be decrypted
        }

        // decrypt chars that need to be decrypted using decrypt map
        char& decryptedChar = decryptMap[charToDecrypt]; 

        if (message[i] == tolower(message[i]))  // is lower case
            result += tolower(decryptedChar);
        else                                      // is upper case
            result += toupper(decryptedChar);
    }

    return result;
}