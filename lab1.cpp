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


int main() {
    textbackground(BLACK);
    textcolor(WHITE);
    clrscr();

    window(15, 15, 65, 20);
    for (int i = 7; i <= 15; ++i) {
        textbackground(i);
        for (int j = 0; j <= 15; ++j) {
            textcolor(j);
            cprintf("background:  ");
            cputsColor(i);
            cprintf(" symbol: %d", j);
            for (int k = 1; k <= 3; ++k) {
                cputs("\n");
            }
            cputs("\r");
            delay(800);
            j++;
            textcolor(j);
            cprintf("background:  ");
            cputsColor(i);
            cprintf(" symbol: %d", j);
            delay(800);
            clrscr();

        }
    }
    getch();
    return 0;
}
