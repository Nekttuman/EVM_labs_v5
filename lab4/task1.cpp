#include "dos.h"
#include "conio.h"
#include "stdio.h"

#define TOP 0
#define RIGHT 1
#define LEFT 2
#define BOTTOM 3


const int X1 = 10, Y1 = 8, 
          X2 = 70, Y2 = 18;


void incrY(int& y);
void decrY(int& y);
void incrX(int& x);
void decrX(int& x);



int main() {
    clrscr();

    int x = 10;
    int y = 10;

    int ch = 0;
    int direct = RIGHT;

    window(X1, Y1, X2, Y2);
    textbackground(WHITE);
    textcolor(BLACK);

    do {
        clrscr();
        gotoxy(x, y);
        putch('*');
        delay(100);

        if (direct == RIGHT) decrX(x);
        if (direct == LEFT) incrX(x);
        if (direct == TOP) decrY(y);
        if (direct == BOTTOM) incrY(y);

        if (kbhit()){
            ch = getch();

            switch (ch) {
                case 63: //vert
                    direct = (direct == RIGHT) ? LEFT: RIGHT; 
                    break;
                case 64: //horiz
                    direct = (direct == BOTTOM) ? TOP: BOTTOM;
                    break;
            }
        }
    } while (ch != 27);

    return 0;
}



void incrY(int& y){
    if (y < Y2-Y1+1)
        ++y;
}

void decrY(int& y){
    if (y > 1)
        --y;   
}

void incrX(int& x){
    if (x < X2-X1+1)
        ++x;
}

void decrX(int& x){
    if (x > 1)
       --x;
}

