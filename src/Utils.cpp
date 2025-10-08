#include "Utils.h"
#include <termios.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>

// 获取单个字符输入（不回显）
char getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

// 清屏函数
void clearScreen() {
    system("clear");
}
