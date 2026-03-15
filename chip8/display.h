#ifndef DISPLAY_H
#define DISPLAY_H

#pragma once
#include <cstdint>
#include <vector>

static const int WIDTH = 64;
static const int HEIGHT = 32;

class Display {
    std::vector<std::vector<uint8_t> > screen;

 public:
    Display();

    void clear();
    void setPixel(int x, int y, uint8_t value);
    bool drawSprite(int x, int y, const std::vector<uint8_t>& sprite);
    void render();
    uint8_t getPixel(int x, int y) const;
};

#endif 