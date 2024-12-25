#include "iostream.h"
#include "graphics.h"
#include "stdio.h"
#include "conio.h"
#include <bios.h>
#include <dos.h>


int GrDriver = DETECT;
int GrMode;
int i = 0;


void interrupt(*oldInt09h)
(...);


void cputsColor(int i) {
    switch (i) {
        case BLACK:
            setbkcolor(BLACK);
            break;
        case BLUE:
            setbkcolor(BLUE);
            break;
        case GREEN:
            setbkcolor(GREEN);
            break;
        case CYAN:
            setbkcolor(CYAN);
            break;
        case RED:
            setbkcolor(RED);
            break;
        case MAGENTA:
            setbkcolor(MAGENTA);
            break;
        case BROWN:
            setbkcolor(BROWN);
            break;
        case LIGHTGRAY:
            setbkcolor(LIGHTGRAY);
            break;
        case DARKGRAY:
            setbkcolor(DARKGRAY);
            break;
        case LIGHTBLUE:
            setbkcolor(LIGHTBLUE);
            break;
        case LIGHTGREEN:
            setbkcolor(LIGHTGREEN);
            break;
        case LIGHTCYAN:
            setbkcolor(LIGHTCYAN);
            break;
        case LIGHTRED:
            setbkcolor(LIGHTRED);
            break;
        case LIGHTMAGENTA:
            setbkcolor(LIGHTMAGENTA);
            break;
        case YELLOW:
            setbkcolor(YELLOW);
            break;
        case WHITE:
            setbkcolor(WHITE);
            break;
        default:
            break;
    }
}


void interrupt

far nineHandle(...) {
    unsigned char c = inp(0x60);
    switch (c) {
        case 62:
            cputsColor(i);
            i++;
            if (i == 16) { i = 0; }
    }
    (*oldInt09h)();
}


int main() {
    char c;
    clrscr();
    initgraph(&GrDriver, &GrMode, "C:\\TurboC3\\BGI");
    auto *grRes = new int(graphresult());
    if (*grRes != grOk) {
        cputs(grapherrormsg(*grRes));
        cputs("\n\rPress anything to exit...");
        getch();
        return *grRes;
    } else {
        delete grRes;
    }
    oldInt09h = _dos_getvect(0x09);


    _dos_setvect(0x09, nineHandle);
    while (1) {
        if (kbhit() && getch() == 27) {
            _dos_setvect(0x09, oldInt09h);
            return 0;
        }
    }

}
