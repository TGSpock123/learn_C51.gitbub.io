#include <REGX52.H>
#include "button.h"
#include "delay.h"
#include "useful.h"

unsigned char mod = 2;

//waring: but >= 0 && but <= 3
unsigned char button_push (unsigned char but, void (* func_p) (unsigned char, unsigned char))
{
	unsigned char mask = 1 << but;
	
	if (!(P3 & mask))
	{
		delay_x_ms (20);
		while (!(P3 & mask));
		delay_x_ms (20);
		
		func_p (but);
	}

	return 1;
}
