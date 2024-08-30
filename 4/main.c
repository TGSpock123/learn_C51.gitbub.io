#include <REGX52.H>
#include "run_lcd.h"

int main (void)
{
	long int show = 0;
	lcd_init ();
	lcd_string ("Hello, LCD! ", 0, 0);
	
	while (1)
	{
		lcd_num (show, 1, 0);
		(show >= 3600) ? (show = 0) : (1);
		show += 60;
		delay_s ();
	}
	
	return 0;
}
