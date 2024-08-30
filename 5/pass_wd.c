#include "pass_wd.h"
#include "run_lcd.h"
#include "delay.h"

unsigned char xdata words[][17] = {
	"Password Set:   ", 
	"Old Password:   ", 
	"New Password:   ", 
	"Password Setted!",
	"Input Password: ", 
	"Correct!", 
	"Wrong.  ",
	"        ",
	"Change Password:"
};

void pass_wd_to_str (unsigned long pass_wd, unsigned char * str)
{
	unsigned char cot;
	
	for (cot = 1; cot <= PASS_WD_LEN; cot ++)
	{
		str[PASS_WD_LEN - cot] = pass_wd % 10 + 48;
		pass_wd /= 10;
	}
}

void input_pass_wd (unsigned long * pass_wd, unsigned char input)
{
	(*pass_wd < 100000) ? (*pass_wd = *pass_wd * 10 + input) : (0);
}

void del_pass_wd (unsigned long * pass_wd)
{
	*pass_wd /= 10;
}

unsigned char compare_pass_wd (unsigned long * pass_wd_inp, unsigned long pass_wd)
{
	unsigned char r_w = 0;
	
	(*pass_wd_inp == pass_wd) ?
	(lcd_string (words[5], 1, 7), r_w = 1) :
	(lcd_string (words[6], 1, 7));
	delay_x_ms (1500);
	*pass_wd_inp = 0;
	lcd_string (words[7], 1, 7);
	
	return r_w;
}
