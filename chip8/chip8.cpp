#include "chip8.h"
#include <fstream>
#include <cstring>

Chip8::Chip8() {
    initialize();
}

void Chip8::initialize() {
    PC = 0x200;  // program counter 
    I = 0;   // index register
    sp = 0;  // stack pointer

    memset(memory, 0 ,sizeof(memory));
    memset(gfx, 0, sizeof(gfx));
    memset(keypad, 0, sizeof(keypad));
    memset(stack, 0, sizeof(stack));
    memset(V, 0, sizeof(V));

    delay_timer = sound_timer =0;

    loadFont();

}

void Chip8::loadFont() {
    uint8_t font[16*5] = {
        0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
        0x20, 0x60, 0x20, 0x20, 0x70, // 1
        0xF0, 0x10, 0x20, 0x40, 0xF0, // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 5
        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
        0xF0, 0x80, 0xF0, 0x10, 0xF0, // 7
        0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
        0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
        0xF0, 0x90, 0xF0, 0x90, 0x90, // A
        0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
        0xF0, 0x80, 0x80, 0x80, 0xF0, // C
        0xE0, 0x90, 0x90, 0x90, 0xE0, // D
        0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
        0xF0, 0x80, 0xF0, 0x80, 0x80, // F
    };
    for (int i=0; i<80; i++) {
        memory[i] = font[i];
    }
}

void Chip8::loadRom(const char* filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file) return;

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    char* buffer = new char[size];
    file.read(buffer, size);

    for (int i=0; i<size; i++) {
        memory[0x200 +i] = buffer[i];
    }

    delete[] buffer;
}

uint16_t Chip8::fetch() {
    return (memory[PC] << 8) | memory[PC+1];
}

void Chip8::OP_00E0() {
    memset(gfx, 0, sizeof(gfx));
}

void Chip8::decode(uint16_t opcode) {
    uint8_t nibble1 = (opcode >> 12) & 0xF;
    uint8_t nibble2 = (opcode >> 8) & 0xF;
    uint8_t nibble3 = (opcode >> 4) & 0xF;
    uint8_t nibble4 = opcode & 0xF;

    switch (nibble1) {
        case 0:
            switch (nibble2) {
                case 0:
                    Chip8::OP_00E0();
}
    }
}

void Chip8::cycle() {
    uint16_t opcode = fetch();
    PC += 2;

    decode(opcode);
}