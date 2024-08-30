#include <REGX52.h>
#include "run_lcd.h"
#include "delay.h"
#include "useful.h"

#define RS P2_6
#define RW P2_5
#define E  P2_7
#define DATA P0

void lcd_cmd (unsigned char cmd)
{
  RS = 0;
  RW = 0;
  DATA = cmd;
  E = 1;
  delay_x_ms (1);
  E = 0;
}

void lcd_data (unsigned char dat)
{
    RS = 1;
    RW = 0;
    DATA = dat;
    E = 1;
    delay_x_ms (1);
    E = 0;
}

void lcd_init (void)
{
  lcd_cmd(0x38);
  lcd_cmd(0x0C); 
  lcd_cmd(0x06); 
  lcd_cmd(0x01); 
	
  delay_x_ms (2);
}

void lcd_set_cursor (unsigned char row, unsigned char col)
{
  unsigned char pos = col;
	
	(row) ? (pos += 0x40) : (1);
	
  lcd_cmd(0x80 | pos);
}

void lcd_string (char * str, unsigned char row, unsigned char col)
{
	lcd_set_cursor (row, col);
	
  while (*str)
  {
	 lcd_data(*str++);
	}
}

void lcd_num (long int num, unsigned char row, unsigned char col)
{
	unsigned char str[17];
	
	num_to_str (num, str);
	lcd_string (str, row, col);
}
