#include "cpu.h"
#include "display.h"
#include "input.h"

int main() {
    Display display;
    Input input;
    CPU cpu(display, input);

    cpu.loadROM("pong.ch8");

    while (true) {
        cpu.cycle();      
        display.render(); 
    }

    return 0;
}
