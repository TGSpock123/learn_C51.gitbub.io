#include "delay.h"
#include <REGX52.H>


void delay_s (void)
{
	delay_hf_s ();
	delay_hf_s ();
}

void delay_hf_s (void)
{
	int count;
	for (count = 0; count < 500; count ++)
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
