#include "cpu.h"

CPU::CPU(Display& display, Input& input) : display(display), input(input) {}

void CPU::loadROM(const char* filename) {
    chip8.loadRom(filename);
}

void CPU::cycle() {
    input.update(chip8.keypad);
    chip8.cycle();

    for (int y = 0; y < 32; ++y) {
        for (int x = 0; x < 64; ++x) {
            display.setPixel(x, y, chip8.gfx[y * 64 + x]);
        }
    }
}
