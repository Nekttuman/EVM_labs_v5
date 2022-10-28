#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

const char *colors[] = {"BLACK", "BLUE", "GREEN", "CYAN", "RED", "MAGENTA",
						"BROWN", "LIGHTGRAY", "DARKGRAY", "LIGHTBLUE", "LIGHTGREEN", "LIGHTCYAN",
						"LIGHTRED", "LIGHTMAGENTA", "YELLOW", "WHITE"};

struct coord
{
	int x;
	int y;
	coord(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};

int main(void)
{

	int gd, gm, err;

	detectgraph(&gd, &gm); /* определение номера драйвера и режима */

	err = graphresult(); /* получение кода завершения */
	if (err)
	{
		printf(" % s", grapherrormsg(err));
		getch();
		return 1;
	}

	initgraph(&gd, &gm, ""); /* инициализация системы */

	err = graphresult(); /* получение кода завершения */

	if (err)
	{
		printf(" % s", grapherrormsg(err));
		getch();
		return 2;
	}

	/* ................различные операторы..............*/

	int maxx = getmaxx();
	int maxy = getmaxy();
	setbkcolor(15);
	setcolor(8);
	//settextstyle(0, HORIZ_DIR, 0);

	/* ....................... Axis .........................*/
	setviewport(0, 0, 500, 500, 1);

	coord center(50, 300);
	outtextxy(550 - 15, 308, "10 pi");

	//			Ox
	line(10, 300, 620, 300);

	// x-arrow
	setlinestyle(0, 0, 3);
	line(620, 300, 610, 295);
	line(620, 300, 610, 305);
	setlinestyle(0, 0, 1);

	for (int i = 50; i <= 600; i += 50)
	{
		line(i, 301, i, 305);
		for (int j = i; j < i + 50 && i < 600; j += 5)
			line(j, 301, j, 302);
	}
	outtextxy(150 - 15, 308, "2 pi");
	outtextxy(250 - 15, 308, "4 pi");
	outtextxy(350 - 15, 308, "6 pi");
	outtextxy(450 - 15, 308, "8 pi");
	outtextxy(550 - 15, 308, "10 pi");

	outtextxy(620, 310, "X");

	// 			Oy
	line(50, 440, 50, 30);

	// y-arrow
	setlinestyle(0, 0, 3);
	line(50, 30, 45, 40);
	line(50, 30, 55, 40);
	setlinestyle(0, 0, 1);

	// Y notches
	for (i = 60; i <= 300; i += 30)
	{
		line(49, i, 45, i);
		for (int j = i; j < i + 30; j += 6)
			line(48, j, 49, j);

		outtextxy(35, 238, "2");
		outtextxy(35, 178, "4");
		outtextxy(35, 118, "6");
		outtextxy(35, 58, "8");
	}

	outtextxy(30, 40, "Y");

	float y_pixels_per_unit = 30;
	float x_pixels_per_unit = M_PI / 50;

	/* ....................... Graphic.........................*/

	float y, x;
	for (float step = 0; step < 550; ++step)
	{
		x = step * x_pixels_per_unit;
		y = pow(cos(x / 2), 3) + sqrt(x);
		y = y * y_pixels_per_unit;
		putpixel((center.x + step), (center.y - y), GREEN);
		putpixel((center.x + step), (center.y - y) - 1, GREEN);
	}

	getch();

	/* ....................... IN NEW WINDOW .........................*/

	setviewport(80, 80, 560, 400, 1);
	maxx = 560 - 80;
	maxy = 400 - 80;

	// clear
	setbkcolor(14);
	bar(0, 0, maxx, maxy);

	// create border
	setlinestyle(0, 0, 3);
	line(0, 0, maxx - 2, 0);
	line(0, 0, 0, maxy - 2);
	line(maxx - 2, 0, maxx - 2, maxy - 2);
	line(0, maxy - 2, maxx - 2, maxy - 2);

	outtextxy(maxx / 2 - 40, 5, "NEW WINDOW");

	/* ....................... Axis .........................*/
	setviewport(0, 0, 500, 500, 1);

	//coord center(50, 300);
	outtextxy(550 - 15, 308, "10 pi");

	//			Ox

	setlinestyle(0, 0, 1);
	line(10, 300, 470, 300);

	// x-arrow
	setlinestyle(0, 0, 3);
	line(470, 300, 460, 295);
	line(470, 300, 460, 305);
	setlinestyle(0, 0, 1);

	for (i = 30; i <= 400; i += 50)
	{
		line(i, 301, i, 305);
		for (int j = i; j < i + 50 && i < 400; j += 5)
			line(j, 301, j, 302);
	}
	outtextxy(130 - 15, 308, "4 pi");
	outtextxy(230 - 15, 308, "8 pi");
	outtextxy(330 - 15, 308, "12 pi");
	outtextxy(430 - 15, 308, "16 pi");

	outtextxy(460, 270, "X");

	// 			Oy
	line(30, 440, 30, 30);

	// y-arrow
	setlinestyle(0, 0, 3);
	line(30, 30, 25, 40);
	line(30, 30, 35, 40);
	setlinestyle(0, 0, 1);

	// Y notches
	for (i = 60; i <= 300; i += 30)
	{
		line(29, i, 25, i);
		for (int j = i; j < i + 30; j += 6)
			line(28, j, 29, j);

		outtextxy(15, 238, "2");
		outtextxy(15, 178, "4");
		outtextxy(15, 118, "6");
		outtextxy(15, 58, "8");
	}

	outtextxy(10, 40, "Y");

	y_pixels_per_unit = 30;
	x_pixels_per_unit = M_PI / 25;

	/* ....................... Graphic.........................*/

	center.x -= 20;
	//float y, x;
	float max_val = 0;
	for (step = 25 * 1.5; step < 25 * 15; ++step)
	{
		x = step * x_pixels_per_unit;
		y = pow(cos(x / 2), 3) + sqrt(x);
		if (y > max_val)
			max_val = y;
		y = y * y_pixels_per_unit;
		putpixel((center.x + step), (center.y - y), GREEN);
		putpixel((center.x + step), (center.y - y) - 1, GREEN);
		putpixel((center.x + step), (center.y - y) + 1, GREEN);
	}

	getch();

	/* ....................... MAX VAL.........................*/

	setviewport(0, 0, 200, 100, 1);

	setfillstyle(SOLID_FILL, BLUE);
	bar(0, 0, 200, 100);
	setcolor(WHITE);
	char *s_max_value;
	sprintf(s_max_value, "%f", max_val);

	outtextxy(10, 10, "MAX VALUE IN ");
	outtextxy(10, 30, "[1.5 pi ; 15 pi]");
	outtextxy(10, 50, s_max_value);
	getch();


	closegraph();
	return EXIT_SUCCESS;
}
