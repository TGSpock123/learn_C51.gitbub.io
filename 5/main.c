#include <REGX52.H>
#include "delay.h"
#include "run_lcd.h"
#include "pass_wd.h"
#include "keyboard.h"

extern unsigned char xdata words[9][17];

int main (void)
{
	unsigned long pass_wd_set = 0, pass_wd_inp = 0;
	unsigned char input = 0, str[7], mod = 0;
	
	lcd_init ();
	lcd_string (words[0], 0, 0);
	
	while (1)
	{
		pass_wd_to_str (pass_wd_inp, str);
		lcd_string (str, 1, 0);
		
		input = which_key ();
		
		switch (input)
		{
			case BUT_ONE:
				input_pass_wd (&pass_wd_inp, 1);
				break;
			case BUT_TWO:
				input_pass_wd (&pass_wd_inp, 2);
				break;
			case BUT_THR:
				input_pass_wd (&pass_wd_inp, 3);
				break;
			case BUT_FOU:
				input_pass_wd (&pass_wd_inp, 4);
				break;
			case BUT_FIV:
				input_pass_wd (&pass_wd_inp, 5);
				break;
			case BUT_SIX:
				input_pass_wd (&pass_wd_inp, 6);
				break;
			case BUT_SEV:
				input_pass_wd (&pass_wd_inp, 7);
				break;
			case BUT_EIG:
				input_pass_wd (&pass_wd_inp, 8);
				break;
			case BUT_NIN:
				input_pass_wd (&pass_wd_inp, 9);
				break;
			case BUT_ZER:
				input_pass_wd (&pass_wd_inp, 0);
				break;
			case BUT_BKS:
				del_pass_wd (&pass_wd_inp);
				break;
			case BUT_CNF:
				switch (mod)
				{
					case 0:
						lcd_string (words[3], 0, 0);
						pass_wd_set = pass_wd_inp;
						mod = 1;
						pass_wd_inp = 0;
						delay_x_ms (1500);
						lcd_string (words[4], 0, 0);
						break;
					case 1:
						lcd_string (words[4], 0, 0);
						compare_pass_wd (&pass_wd_inp, pass_wd_set);
						break;
					case 2:
						if (compare_pass_wd (&pass_wd_inp, pass_wd_set))
						{
							mod = 0;
							lcd_string (words[0], 0, 0);
						}
						break;
					default:
						break;
				}
				break;
			case BUT_CHG:
				if (mod == 1)
				{
					mod = 2;
					lcd_string (words[8], 0, 0);
					delay_x_ms (800);
					lcd_string (words[1], 0, 0);
				}
				break;
			case BUT_CAN:
				pass_wd_inp = 0;
				(mod) ? (mod = 1, lcd_string (words[4], 0, 0)) : (0);
				break;
			default:
				break;
		}
	}
	
	return 0;
}
