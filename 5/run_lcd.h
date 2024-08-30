#ifndef _RUN_LCD_H_
#define _RUN_LCD_H_

void lcd_init(void);
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char dat);
void lcd_set_cursor (unsigned char row, unsigned char col);
void lcd_string (char * str, unsigned char row, unsigned char col);

#endif
