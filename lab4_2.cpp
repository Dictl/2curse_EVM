#include "iostream.h"
#include "graphics.h"
#include "stdio.h"
#include "conio.h"
#include <bios.h>
#include <dos.h>

int GrDriver = DETECT;
int GrMode;

int my_getch() {
    union REGS regs;
    regs.h.ah = 0x7; // Функция BIOS для чтения с клавиатуры
    int86(0x21, &regs, &regs);
    return regs.h.al;
}

int main() {
    char c;
    int x1 = 15, y1 = 15, x2 = 65, y2 = 20;
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
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    setcolor(WHITE);
    bar(x1, y1, x2, y2);
    setcolor(RED);
    outtextxy(x1, y1 + 2, "'");

    int main_cycle = 1;
    while (main_cycle == 1) {
        c = my_getch();
        switch (c) {
            case 77:
                setcolor(WHITE);
                bar(x1, y1, x2, y2);
                setcolor(RED);
                x1++;
                if (x1 == 64) { x1 = 15; }
                outtextxy(x1, y1 + 2, "'");
                break;
            case 75:
                setcolor(WHITE);
                bar(x1, y1, x2, y2);
                setcolor(RED);
                x1--;
                if (x1 == 14) { x1 = 63; }
                outtextxy(x1, y1 + 2, "'");
                break;
            case 27:
                main_cycle = 0;
                break;
        }
    }
    closegraph();
    return 0;
}
