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
	unsigned char data i, j;

	_nop_();
	_nop_();
	_nop_();
	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}
