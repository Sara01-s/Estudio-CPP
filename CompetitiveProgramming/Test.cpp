#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

std::string decryptMessage(const std::string& message, const std::string& freqLang) {
    std::unordered_map<char, int> frequency;
    for (char c : message) {
        if (isalpha(c)) {
            c = tolower(c);
            frequency[c]++;
        }
    }

    std::string decryptedMessage = message;
    std::sort(decryptedMessage.begin(), decryptedMessage.end(), [&](char a, char b) {
        char la = tolower(a);
        char lb = tolower(b);
        if (!isalpha(a) || !isalpha(b)) {
            return a < b;
        } else {
            return frequency[la] > frequency[lb];
        }
    });

    std::unordered_map<char, char> decryptionMap;
    for (size_t i = 0; i < freqLang.length(); i++) {
        char c = freqLang[i];
        char decryptedChar = decryptedMessage[i];
        decryptionMap[decryptedChar] = c;
    }

    std::string result;
    for (char c : message) {
        if (isalpha(c)) {
            result += decryptionMap[tolower(c)];
        } else {
            result += c;
        }
    }

    return result;
}

int main() {
    std::string FREQ_LANG = "TEOAISRHNUCMDLGWFPYKJBVQX";
    std::string MENSAJE = "Bgc-bfufb tegaedppqna ql aggv zge xof tegaedppfe'l lgjb.\n"
                          "Xof adpf vflqanfe logjbvn'x hf pdwqna d cgebv qn coqro xof tbdkfe ql mjlx d lpdbb tdex. Xof tbdkfe QL XOF HGLL; qx'l kgje vjxk xg fnxfexdqn oqp ge ofe.\n"
                          "Zgrjl ql d pdxxfe gz vfrqvqna codx xoqnal kgj def ngx agqna xg vg.\n"
                          "Xof rglx gz dvvqna d zfdxjef qln'x mjlx xof xqpf qx xdwfl xg rgvf qx. Xof rglx dblg qnrbjvfl xof dvvqxqgn gz dn ghlxdrbf xg zjxjef fstdnlqgn. Xof xeqrw ql xg tqrw xof zfdxjefl xodx vgn'x zqaox fdro gxofe. - Mgon Rdepdrw.\n"
                          "(ccc.adpdljxed.rgp/uqfc/nfcl/234346?utkjpvbjr)\n"
                          "(ccc.hedqnkijgxf.rgp/ijgxfl/djxogel/m/mgon_rdepdrw.oxpb)";

    std::string decrypted = decryptMessage(MENSAJE, FREQ_LANG);
    std::cout << decrypted << std::endl;

    return 0;
}
