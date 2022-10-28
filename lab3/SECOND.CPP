#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

const char* colors[] = { "BLACK", "BLUE", "GREEN", "CYAN", "RED", "MAGENTA",
 "BROWN", "LIGHTGRAY", "DARKGRAY", "LIGHTBLUE", "LIGHTGREEN", "LIGHTCYAN",
	    "LIGHTRED", "LIGHTMAGENTA", "YELLOW", "WHITE" };






int main(void)
{

	int gd, gm, err;

	detectgraph(&gd, &gm); /* определение номера драйвера и режима */

	err = graphresult(); /* получение кода завершения */

	if (err) { printf(" % s", grapherrormsg(err));getch(); return 1; }

	initgraph(&gd, &gm, ""); /* инициализация системы */

	err = graphresult(); /* получение кода завершения */

	if (err) { printf(" % s", grapherrormsg(err));getch(); return 2; }

	/* ................различные операторы..............*/

	int maxx = getmaxx();
	int maxy = getmaxy();
	setbkcolor(15);
	setcolor(8);
	settextstyle(0, HORIZ_DIR, 0);


	outtextxy(50,300,"i m gay");
	outtextxy(500,300,"time");
	outtextxy(20,30,"im not gay");
	line(10, 300, 550, 300);
	line(50,440,50, 50);

	moveto(50,300); //центр координатной плоскости, отсчет отсюда (мб не робит не чекал)




	getch();

	closegraph(); /* завершение работы системы */
	cprintf("maxx=%d maxy=%d\r\n", maxx, maxy); //640 480
	getch();

	return 0;

}
