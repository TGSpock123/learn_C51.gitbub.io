#include "keyboard.h"
#include "delay.h"
#include <REGX52.H>

unsigned char which_key (void)
{
	unsigned char num = 0, mask, mask_1;
	
	for (mask = 0x8; mask > 0; mask >>= 1)
	{
		P1 = ~mask;
		delay_x_ms (1);
		
		for (mask_1 = 0x80; mask_1 > 0x8; mask_1 >>= 1)
		{
			if (!(P1 & mask_1))
			{
				delay_x_ms (10);
				while (!(P1 & mask_1));
				delay_x_ms (10);
				
				num = (mask) | (mask_1);
				return num;
			}
		}
	}
	
	return num;
}
