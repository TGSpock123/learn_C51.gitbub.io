#ifndef _PASS_WD_H_
#define _PASS_WD_H_

#define PASS_WD_LEN 6
#define BUT_ONE 136
#define BUT_TWO 132
#define BUT_THR 130
#define BUT_FOU 72
#define BUT_FIV 68
#define BUT_SIX 66
#define BUT_SEV 40
#define BUT_EIG 36
#define BUT_NIN 34
#define BUT_ZER 20
#define BUT_BKS 24
#define BUT_CNF 18
#define BUT_CHG 129
#define BUT_CAN 17

void pass_wd_to_str (unsigned long pass_wd, unsigned char * str);
void input_pass_wd (unsigned long * pass_wd, unsigned char input);
void del_pass_wd (unsigned long * pass_wd);
unsigned char compare_pass_wd (unsigned long * pass_wd_inp, unsigned long pass_wd);

#endif
