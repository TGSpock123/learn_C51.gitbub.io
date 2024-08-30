#include "delay.h"
#include <REGX52.H>

void delay_x_ms (int x)
{
	int i;
	for (i = 0; i < x; i ++)
	{
		delay_ms ();
	}
}

void delay_ms (void)
{
	TMOD &= 0xF0;
	TMOD |= 0x1;
	TL0 = 0x67;
	TH0 = 0xFC;
	TF0 = 0;
	TR0 = 1;
	while (!TF0);
	TR0 = 0;
	TF0 = 0;
}
