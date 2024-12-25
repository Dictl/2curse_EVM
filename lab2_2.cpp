#include <iostream.h>
#include <conio.h>
#include <dos.h>


#define VIDEO 0x10


void cputsColor(int i) {
    switch (i) {
        case BLACK:
            cputs("BLACK");
            break;
        case BLUE:
            cputs("BLUE");
            break;
        case GREEN:
            cputs("GREEN");
            break;
        case CYAN:
            cputs("CYAN");
            break;
        case RED:
            cputs("RED");
            break;
        case MAGENTA:
            cputs("MAGENTA");
            break;
        case BROWN:
            cputs("BROWN");
            break;
        case LIGHTGRAY:
            cputs("LIGHTGRAY");
            break;
        case DARKGRAY:
            cputs("DARKGRAY");
            break;
        case LIGHTBLUE:
            cputs("LIGHTBLUE");
            break;
        case LIGHTGREEN:
            cputs("LIGHTGREEN");
            break;
        case LIGHTCYAN:
            cputs("LIGHTCYAN");
            break;
        case LIGHTRED:
            cputs("LIGHTRED");
            break;
        case LIGHTMAGENTA:
            cputs("LIGHTMAGENTA");
            break;
        case YELLOW:
            cputs("YELLOW");
            break;
        case WHITE:
            cputs("WHITE");
            break;
        default:
            break;
    }
}


void scrollDown(int lines, char x1, char y1) {
    union REGS r;
    for (int i = 1; i < lines; ++i) {
        gotoxy(x1, y1 + i);
        cputs("\r");
        gotoxy(x1, y1);
    }
    int86(0x10, &r, &r);
}

int main() {
    textbackground(BLACK);
    textcolor(WHITE);
    clrscr();
    window(15, 15, 65, 20);
    for (int i = 7; i <= 15; ++i) {
        textbackground(i);
        for (int j = 0; j <= 15; ++j) {
            textcolor(j);
            scrollDown(10, 20, 15);
            cprintf("background:  ");
            cputsColor(i);
            cprintf(" symbol: %d", j);
            cputs("\n");
            delay(800);
            for (int k = 1; k <= 3; ++k) {
                cprintf(" \n");
            }
        }
    }

    getch();
    return 0;
}
