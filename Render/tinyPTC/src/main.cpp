extern "C" { 
    #include "tinyptc.h"
}

#include <cstdint>
#include "main.hpp"


uint32_t ventana[640 * 360];

int main() {

    ptc_open("window", 640, 360);

    for(;;) {
        for (uint32_t i = 0; i < 640*360; i++) {
            ventana[i] = 0xFF000000;
        }

        ptc_update(ventana);
    }

    ptc_close();

    return 0;
}