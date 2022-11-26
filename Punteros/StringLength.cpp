// Implementación de string_length
#include <iostream>

using namespace std;

int StringLength(const char*);

int main(int argc, char** argv) {

    char _nombre[5] = "Sara";
    
    cout << "String Length: " << StringLength(_nombre) << endl;

    return 0;
}

int StringLength(const char* string) {

    int count = 0;

    while (*string != '\0') {
        string++;
        count++;
    }

    return count;
}


