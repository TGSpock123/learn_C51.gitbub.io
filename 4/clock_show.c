#include <REGX52.H>
#include "delay.h"
#include "clock_show.h"

int clock_num[] = {
	ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, DOT
};

int clock_letter[] = {
	LETT_A, LETT_B, LETT_C, LETT_D, LETT_E, LETT_F
};

//waring: loc >= 0 && loc <= 7, num >= 0 && num <= 10;
void clock_show_num (unsigned char loc, unsigned char num)
{
	P2 = (7 - loc) << 2;
	P0 = clock_num[num];
	delay_ms ();
	P0 = 0;
}
