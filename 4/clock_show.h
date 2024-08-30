#ifndef _CLOCK_SHOW_H_
#define _CLOCK_SHOW_H_

#define ZERO 0x3F
#define ONE 0x6
#define TWO 0x5B
#define THREE 0x4F
#define FOUR 0x66
#define FIVE 0x6D
#define SIX 0x7D
#define SEVEN 0x7
#define EIGHT 0x7F
#define NINE 0x6F
#define DOT 0x80
#define LETT_A 0x77
#define LETT_B 0x7C
#define LETT_C 0x39
#define LETT_D 0x5E
#define LETT_E 0x79
#define LETT_F 0x71

extern int clock_num[];
extern int clock_letter[];

void clock_show_num (unsigned char loc, unsigned char num);

#endif
