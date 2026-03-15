#ifndef CPU_H
#define CPU_H

#include "chip8.h"
#include "display.h"
#include "input.h"

class CPU {
    Chip8 chip8;
    Display& display;
    Input& input;

 public:
    CPU(Display& display, Input& input);
    void loadROM(const char* filename);
    void cycle();
};

#endif
