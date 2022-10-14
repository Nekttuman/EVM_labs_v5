#include "conio.h"
#include "dos.h"


const char* colors[] = {"BLACK", "BLUE", "GREEN", "CYAN", "RED", "MAGENTA", "BROWN",
			"LIGHTGRAY", "DARKGRAY", "LIGHTBLUE", "LIGHTGREEN", "LIGHTCYAN",
			"LIGHTRED", "LIGHTMAGENTA", "YELLOW", "WHITE"};

void scroll(int direction, int lines, char l_row, char l_col, char r_row, char r_col, char attr)
{
    union REGS r;
    if (direction)
    {
	r.h.al = lines;
	r.h.ah = direction;
    }
    else
    {
        r.h.al = lines;
        r.h.ah = 6;
    }
    r.h.ch = l_row;
    r.h.cl = l_col;
    r.h.dh = r_row;
    r.h.dl = r_col;
    r.h.bh = attr;
    int86(0x10, &r, &r);
}

void print(short with_scroll)
{
    const short x1 = 10, y1 = 8, x2 = 70, y2 = 18, colors_num = 16;
    const int T = 700;
	
    clrscr();
    window(x1, y1, x2, y2);
    textattr(112);
    for (int bgColNum = 0; bgColNum < colors_num; bgColNum++)
    {
        textbackground(bgColNum);
        for (int txtColNum = 0; txtColNum < colors_num; ++txtColNum)
        {
            textcolor(txtColNum);

            cprintf("\r\n%s", colors[bgColNum]);
            cprintf("\r\n%s", colors[txtColNum]);
            cprintf("\r\n");

            if (with_scroll)
                scroll(6, 2, y1 - 1, x1 - 1, y2 - 1, x2 - 1, (bgColNum * 16 | txtColNum));

            delay(T);
        }
    }
    getch();
    clrscr();
}

int main()
{

    print(0);
    return 0;
}
