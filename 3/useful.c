#include <REGX52.H>
#include "useful.h"
#include "clock_show.h"

extern unsigned char count_down[];
extern unsigned char pos;
unsigned long ms_count = 0, shine_count = 0;
unsigned long shine_ms_count = 0;

void count_p_m (unsigned char which_but)
{
	(!which_but || which_but == 1) ? ((!which_but) ? (count_down[pos] --) : (count_down[pos] ++)) : 0;

	(pos > 0) ?
	((count_down[pos] == 60) ? (count_down[pos] = 0) : 
	((count_down[pos] == 255) ? (count_down[pos] = 59) : 1)) :
	((count_down[pos] == 24) ? (count_down[pos] = 0) : 
	((count_down[pos] == 255) ? (count_down[pos] = 23) : 1));
}

void change_pos (unsigned char which_but)
{
	(which_but == 2) ? (pos --) : (pos ++);

	(pos == 3) ? (pos = 0) : ((pos == 255) ? (pos = 2) : 1);
}

void timer1_init (void) 
{
  TMOD &= 0x0F;
  TMOD |= 0x01;
  TH1 = 0x67;
  TL1 = 0xFC; 
	TF1 = 0;
  ET1 = 1;
  EA = 1;
  TR1 = 1;
}


void timer1_ISR (void) interrupt 3
{
	TH1 = 0x67;
  TL1 = 0xFC; 
  ms_count++;
	
  if (ms_count == 189) 
	{
		count_down[2] ++;
    ms_count = 0;
  }
	
	(count_down[2] == 60) ? (count_down[2] = 0, count_down[1] ++) : (0);
	(count_down[1] == 60) ? (count_down[1] = 0, count_down[0] ++) : (0);
	(count_down[0] == 24) ? (count_down[0] = 0) : (0);
}
