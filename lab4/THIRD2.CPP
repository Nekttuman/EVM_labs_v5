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



int _getch(){
    union REGS r;
	r.h.ah = 16;
	int86(0x16, &r, &r);
	return r.h.ah;
}

int _getche(){
    union REGS r;
	r.h.ah = 0;
	int86(0x16, &r, &r);
    putch(r.h.ah);
	return r.h.ah;
} 

int _kbhit(){
    union REGS r;
	r.h.ah = 01;
	int86(0x16, &r, &r);

	return (r.x.flags != 12995);
}

int _bioskey(int cmd){
    union REGS r;
    if (cmd == 0)
        r.h.ah = 0;
    else if (cmd == 1)
        r.h.ah = 1;
    else if (cmd == 2)
        r.h.ah = 2;

    int86(0x16,&r,&r);
    return r.x.ax; 
}



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
       if (direct == LEFT) incrY(x);
       if (direct == TOP) decrY(y);
       if (direct == BOTTOM) incrY(y);

       if (_kbhit()){
	   ch = _getch();

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

    /*do {
        ch = getch();
        putch(ch);
        } while (ch != 27);*/


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

