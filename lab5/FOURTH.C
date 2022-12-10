#include "dos.h"
#include "conio.h"
#include "stdio.h"


#define C0  16.35          //  |
#define Cs0  17.32         //      |||||||||||||
#define D0  18.35          //  |
#define Ds0  19.45         //      |||||||||||||
#define E0  20.60          //  |
#define F0  21.83          //  |
#define Fs0  23.12         //      |||||||||||||
#define G0  24.50          //  |
#define Gs0  25.96         //      |||||||||||||
#define A0  27.50          //  |
#define As0  29.14         //      |||||||||||||
#define B0  30.87          //  |
#define C1  32.70          //  |
#define Cs1  34.65         //      |||||||||||||
#define D1  36.71          //  |
#define Ds1  38.89         //      |||||||||||||
#define E1  41.20          //  |
#define F1  43.65          //  |
#define Fs1  46.25         //      |||||||||||||
#define G1  49.00          //  |
#define Gs1  51.91         //      |||||||||||||
#define A1  55.00          //  |
#define As1  58.27         //      |||||||||||||
#define B1  61.74          //  |
#define C2  65.41          //  |
#define Cs2  69.30         //      |||||||||||||
#define D2  73.42          //  |
#define Ds2  77.78         //      |||||||||||||
#define E2  82.41          //  |
#define F2  87.31          //  |
#define Fs2  92.50         //      |||||||||||||
#define G2  98.00          //  |
#define Gs2  103.8         //      |||||||||||||
#define A2  110.0          //  |
#define As2  116.5         //      |||||||||||||
#define B2  123.5          //  |
#define C3  130.8          //  |
#define Cs3  138.6         //      |||||||||||||
#define D3  146.8          //  |
#define Ds3  155.6         //      |||||||||||||
#define E3  164.82         //  |
#define F3  174.6          //  |
#define Fs3  185.0         //      |||||||||||||
#define G3  196.0          //  |
#define Gs3  207.7         //      |||||||||||||
#define A3  220.0          //  |
#define As3  233.1         //      |||||||||||||
#define B3  246.9          //  |
#define C4  261.6          //  |                  FIRST
#define Cs4  277.2         //      |||||||||||||
#define D4  293.7          //  |
#define Ds4  311.1         //      |||||||||||||
#define E4  329.6          //  |
#define F4  349.2          //  |
#define Fs4  370.0         //      |||||||||||||
#define G4  392.0          //  |
#define Gs4  415.3         //      |||||||||||||
#define A4  440.0          //  |
#define As4  466.2         //      |||||||||||||
#define B4  493.9          //  |
#define C5  523.3          //  |                 SECONSD
#define Cs5  554.4         //      |||||||||||||
#define D5  587.3          //  |
#define Ds5  622.3         //      |||||||||||||
#define E5  659.3          //  |
#define F5  698.5          //  |
#define Fs5  740.0         //      |||||||||||||
#define G5  784.0          //  |
#define Gs5  830.6         //      |||||||||||||
#define A5  880.0          //  |
#define As5  932.3         //      |||||||||||||
#define B5  987.8          //  |
#define C6  1047           //  |                 THIRD
#define Cs6  1109          //      |||||||||||||
#define D6  1175           //  |
#define Ds6  1245          //      |||||||||||||
#define E6  1319           //  |
#define F6  1397           //  |
#define Fs6  1480          //      |||||||||||||
#define G6  1568           //  |
#define Gs6  1661          //      |||||||||||||
#define A6  1760           //  |
#define As6  1865          //      |||||||||||||
#define B6  1976           //  |
#define C7  2093           //  |                  FOURTH
#define Cs7  2217          //      |||||||||||||
#define D7  2349           //  |
#define Ds7  2489          //      |||||||||||||
#define E7  2637           //  |
#define F7  2794           //  |
#define Fs7  2960          //      |||||||||||||
#define G7  3136           //  |
#define Gs7  3322          //      |||||||||||||
#define A7  3520           //  |
#define As7  3729          //      |||||||||||||
#define B7  3951           //  |




void interrupt(*oldvect)();

void interrupt new_int();

int main() {
    clrscr();
    oldvect = getvect(9);

    setvect(9, new_int);

    while (getch() != 27) {}
    nosound();
    setvect(9, oldvect);
    return 0;
}

const float codes[4][24] = { {C0, Cs0, D0, Ds0, E0, F0, Fs0, G0, Gs0, A0, As0, B0,
				    C1, Cs1, D1, Ds1, E1, F1, Fs1, G1, Gs1, A1, As1, B1},
			    {C2, Cs2, D2, Ds2, E2, F2, Fs2, G2, Gs2, A2, As2, B2,
				    C3, Cs3, D3, Ds3, E3, F3, Fs3, G3, Gs3, A3, As3, B3},
			    {C4, Cs4, D4, Ds4, E4, F4, Fs4, G4, Gs4, A4, As4, B4,
				    C5, Cs5, D5, Ds5, E5, F5, Fs5, G5, Gs5, A5, As5, B5},
			    {C6, Cs6, D6, Ds6, E6, F6, Fs6, G6, Gs6, A6, As6, B6,
				    C7, Cs7, D7, Ds7, E7, F7, Fs7, G7, Gs7, A7, As7, B7} };

const int note[52] = {
	-1, -1, -1, 1, 3, -1, 6, 8, 10, -1, -1, -1, -1, -1, -1, -1, 0, 2, 4,
	5, 7, 9, 11, -1, -1, -1, -1, -1, -1, -1, -1, 13, 15, -1, 18, 20, 22,
	-1, -1, -1, -1, -1, -1, -1, 12, 14, 16, 17, 19, 21, 23
};

const int sign[52] = { 49, 50, 51, 52, 53, 54, 55, 56, 57, 48, 45, 61, 0, 0,
                81, 87, 69, 82,  84, 89, 85, 73, 79, 80, 91, 93, 0, 0,
                65, 83, 68,70, 71, 72, 74, 75,76, 59, 96, 0, 0, 0,
                90, 88, 67, 86, 66, 78, 77, 44, 46, 63};


int code;
int octave = 0;

void interrupt new_int() {
    (*oldvect)();
    code = inportb(0x60);

    if (code == 75 && octave > 0)
        --octave;

    else if (code == 77 && octave < 3)
        ++octave;

    else if (code > 0 && code < 53 && note[code] != -1) 
        sound(codes[octave][note[code]]);

    else if (code > 129 && note[code-128] == -1 ) {
        nosound();
        printf("%c", sign[code - 130]);
    }
    else
        nosound();
}



