#include <cstdio>
#include <cstdint>

namespace ECS {

    struct Sprite_t {
        static constexpr uint8_t Width { 13 }, Height { 5 };
        static constexpr uint8_t Resolution { Width * Height };
        const char Image[Resolution];
    };

    struct Entity_t {
        uint32_t PosX, PosY;
        char EntityChar;
        Sprite_t* SpriteData;
    };
    
} // namespace ECS

//----------------------------------------------------------------

void clearConsole() {
    std::puts("\033[H \033[J");
}

void locateCursor(uint8_t x, uint8_t y) {
    std::printf("\033[%d;%dH", y, x);
}

void drawEntity(const ECS::Entity_t& entity) {
    locateCursor(entity.PosX, entity.PosY);
    std::putchar(entity.EntityChar);
}

void drawSprite(const ECS::Entity_t& entity) {
    
    locateCursor(entity.PosX, entity.PosY);

    for (uint32_t i = 0; i < ECS::Sprite_t::Resolution; i++) {

        std::putchar(entity.SpriteData->Image[i]);

        if (i % ECS::Sprite_t::Width == 0) {
            std::putchar('\n');
        }
    }
}

void showCursor(const bool& visible) {
    if (visible) std::printf("\033[?25h");
    else         std::printf("\033[?25l");
}

//----------------------------------------------------------------
int main() {
    

    showCursor(false);

    ECS::Sprite_t sprite { 
                           ' ',
                           ' ', ' ', ' ', ' ', ' ', ' ', '=', ' ', ' ', ' ', ' ', ' ', ' ',
                           '=', ' ', ' ', ' ', ' ', ' ', '=', ' ', ' ', ' ', ' ', ' ', '=',
                           '=', ' ', '=', ' ', '=', ' ', '=', ' ', '=', ' ', '=', ' ', '=',
                           '=', ' ', '=', ' ', '=', ' ', '=', ' ', '=', ' ', '=', ' ', '=',
                           ' ', '=', ' ', ' ', ' ', '=', ' ', '=', ' ', ' ', ' ', '='
                         };

    ECS::Entity_t player { 0, 7, '@', &sprite };

    clearConsole();

    drawSprite(player);

    std::getchar();
    
    showCursor(true);
    return 0;
}