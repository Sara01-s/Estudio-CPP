extern "C" { 
    #include "tinyptc.h"
}

#include <cstdint>
#include "main.hpp"

constexpr uint32_t R = 0x00FF0000;                      // red   hex
constexpr uint32_t G = 0x0000FF00;                      // green hex
constexpr uint32_t B = 0x000000FF;                      // blue  hex


uint32_t _window[640 * 360];

uint32_t _sprite[3*2] = {
    R, G, B, 
    R, G, G
};

int main() {

    ptc_open("window", 640, 360);

    for(;;) {
        for (uint32_t i = 0; i < 640*360; ++i) {
            _window[i] = 0x00FF0000;
        }

        uint32_t* screenPtr = _window;
        uint32_t* spritePtr = _sprite;

        for (uint32_t i=0; i < 4; ++i) {
            for (uint32_t j=0; j < 4; ++j) {

                *screenPtr = *spritePtr;

                ++screenPtr;
                ++spritePtr;
            }

            spritePtr += 640 - 4;
        }

        ptc_update(_window);
    }

    ptc_close();

    return 0;
}