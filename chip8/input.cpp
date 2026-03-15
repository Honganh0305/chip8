#include "input.h"
#include <cstring>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

void Input::update(uint8_t keypad[16]) {
    memset(keypad, 0, 16);

    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);

    char ch;
    if (read(STDIN_FILENO, &ch, 1) > 0) {
        switch (ch) {
            case '1': keypad[0x1] = 1; break;
            case '2': keypad[0x2] = 1; break;
            case '3': keypad[0x3] = 1; break;
            case '4': keypad[0x4] = 1; break;
            case '5': keypad[0x5] = 1; break;
            case '6': keypad[0x6] = 1; break;
            case '7': keypad[0x7] = 1; break;
            case '8': keypad[0x8] = 1; break;
            case '9': keypad[0x9] = 1; break;
            case '0': keypad[0x0] = 1; break;
            case 'q': keypad[0xA] = 1; break;
            case 'w': keypad[0xB] = 1; break;
            case 'e': keypad[0xC] = 1; break;
            case 'r': keypad[0xD] = 1; break;
            case 't': keypad[0xE] = 1; break;
            case 'y': keypad[0xF] = 1; break;
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}