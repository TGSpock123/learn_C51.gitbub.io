#include <REGX52.H>
//#include <intrins.h>
#include "delay.h"

int main (void)
{
	unsigned char count;
	unsigned char mask = 0;
	
	while (1)
	{
		/*
		P2 = 0xFE;
		delay_s ();
	
		P2 = 0xFF;
		delay_s ();
		*/
		
		/*
		P2 = 0xFE;
		delay_hf_s ();
		
		for (count = 1; count < 128; P2 -= count, count *= 2, delay_hf_s ());
		*/
		
		/*
		P2 = 0xFF;
		delay_hf_s ();
		
		for (count = 1; count <= 128; P2 -= count, count *= 2, delay_hf_s ());
		*/
		
		for (count = 0; count < 8; count ++)
		{
			P2 = ~ mask;
			(mask == 0) ? (mask += 1) : (mask <<= 1);
			delay_hf_s ();
		}
	}
	
	return 0;
}

/*
void delay_s (void)	//@11.0592MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
*/
