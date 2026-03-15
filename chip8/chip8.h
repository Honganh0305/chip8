#ifndef CHIP8_H
#define CHIP8_H

#include <iostream>
#include <cstdint>
#pragma once

class Chip8 {
    public:
    uint8_t memory[4096];   // 4KB of memory
    uint8_t V[16];          // 16 general purpose registers
    uint16_t I;              // 16 Index register
    uint16_t PC;              // Computer Program Counter

    uint8_t delay_timer;
    uint8_t sound_timer;

    uint8_t stack[16];  // 16 level stack
    uint8_t sp;     // stack pointer

    uint8_t gfx[64*32];       // 64x32 pixel screen
    uint8_t keypad[16];      // 16 key keypad

    Chip8();
    void initialize();
    void loadRom(const char* filename);
    void loadFont(); 

    void cycle();

    private:
    uint16_t fetch();
    void decode(uint16_t opcode);
    void OP_00E0();
};

#endif