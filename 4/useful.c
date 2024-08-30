#include "useful.h"

extern unsigned char count_down[];
extern unsigned char mod;

void if_sldbe_zero (unsigned char * x)
{
	(*x == 0 || *x == 1 << 7) ? ((*x == 0) ? (*x = 1) : (*x = 0)) : (*x <<= 1);
}

void count_p_m (unsigned char which_but)
{
	(!which_but || which_but == 1) ? ((!which_but) ? (count_down[mod] --) : (count_down[mod] ++)) : 0;

	(mod > 0) ?
	((count_down[mod] == 60) ? (count_down[mod] = 0) : 
	((count_down[mod] == 255) ? (count_down[mod] = 59) : 1)) :
	((count_down[mod] == 24) ? (count_down[mod] = 0) : 
	((count_down[mod] == 255) ? (count_down[mod] = 23) : 1));
}

void change_mod (unsigned char which_but)
{
	(which_but == 2) ? (mod --) : (mod ++);

	(mod == 3) ? (mod = 0) : ((mod == 255) ? (mod = 2) : 1);
}

void num_to_str (long int to_str, unsigned char * str)
{
	unsigned char pt = 0, * put_in = str, buffer[17], end = 0;
	
	(to_str < 0) ? (*put_in = '-', end = 1, to_str = - to_str) : (1);
	
	for (; pt < (16 - end) && to_str > 0; pt ++)
	{
		buffer[pt] = to_str % 10 + 48;
		to_str /= 10;
	}
	
	(end == 1) ? (buffer[pt] = '-', pt ++) : (1);
	
	for (end = 0; end < pt; end ++)
	{
		str[end] = buffer[pt - 1 - end];
	}
	
	//str[end] = '\0';
}
