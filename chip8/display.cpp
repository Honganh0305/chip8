#include "display.h"
#include <iostream>

Display::Display() {
    screen.resize(HEIGHT, std::vector<uint8_t>(WIDTH, 0));
}

void Display::setPixel(int x, int y, uint8_t value) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
        screen[y][x] = value;
}

void Display::clear() {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            screen[y][x] = 0;
        }
    }
}

bool Display::drawSprite(int x, int y, const std::vector<uint8_t>& sprite) {
    bool collision = false;

    for (size_t row = 0; row < sprite.size(); ++row) {
        uint8_t byte = sprite[row];

        for (int bit = 0; bit < 8; ++bit) {
            uint8_t pixel = (byte >> (7 - bit)) & 1;

            if (pixel == 0) continue;

            int px = (x + bit) % WIDTH;
            int py = (y + row) % HEIGHT;

            if (screen[py][px] == 1)
                collision = true;

            screen[py][px] ^= 1;
        }
    }

    return collision;
}
uint8_t Display::getPixel(int x, int y) const {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
        return screen[y][x];
    return 0;
}

void Display::render() {
    system("clear"); 

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (screen[y][x])
                std::cout << "██";
            else
                std::cout << "  ";
        }
        std::cout << std::endl;
    }
}

