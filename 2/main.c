#include <REGX52.H>
#include "delay.h"

int main (void)
{
	unsigned char num = /*255*/ 0;
	
	/*
	P2_0 = 1;
	P2_1 = 0;
	*/
	
	P2 = ~num;
	
	while (1)
	{
		/*
		if (!P3_1)
		{
			P2_0 = 0;
			P2_1 = 1;
		}else
		{
			P2_0 = 1;
			P2_1 = 0;
		}
		*/
		
		if (!P3_1)
		{
			delay_x_ms (20);
			while (!P3_1);
			delay_x_ms (20);
			
			/*
			P2_0 = ~P2_0;
			P2_1 = ~P2_1;
			*/
			
			/*
			num --;
			P2 = num;
			*/
			
			(num == 128 || num == 0) ? ((num == 128) ? (num = 0) : (num ++)) : (num <<= 1);
			P2 = ~num;
		}
	}
	
	return 0;
}
