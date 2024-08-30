#include <REGX52.H>
#include "delay.h"
#include "clock_show.h"
#include "button.h"
#include "useful.h"

unsigned char count_down[] = {0, 0, 0};

int main (void)
{
	timer1_init ();
	P2 = 0 << 2;
	
	while (1)
	{
		button_push (0, count_p_m);
		button_push (1, count_p_m);
		button_push (2, change_pos);
		button_push (3, change_pos);
		
		clock_show_num (0, count_down[0] / 10);
		clock_show_num (1, count_down[0] % 10);
		clock_show_num (2, 10);
		clock_show_num (3, count_down[1] / 10);
		clock_show_num (4, count_down[1] % 10);
		clock_show_num (5, 10);
		clock_show_num (6, count_down[2] / 10);
		clock_show_num (7, count_down[2] % 10);
	}
	
	return 0;
}
