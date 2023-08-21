#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define  SUB 1
#define ZERO 4
#define ADD 2
#define BIGSIZE 2
#define SMALLSIZE 1
/********* WRITES*************/

int write_char(int c, char my_buff[], int flg,
		int prcs, int size, int wid);
int write_ptr(int pnd, char my_buff[], int flg,
		int len, char xtraC, char bar, int bar_start, int wid);
int write_unsigned(int is_neg, int pnd, char my_buff, int flg,
		int prcs, int wid, int size);
int write_numb(int pnd, char my_buff[], int flg,
		int prcs, int len, char xtraC, char bar, int wid);
int write_no(int is_neg, int pnd, char my_buff[], int flg,
		int prcs, int size, int wid);
/*************USED************/
int my_digit(char A);
long int size_numb(long int numb, int size);
int put_hexa(char ascii, char my_buff, int x);
long int size_unsigned(unsigned long int numb,  int size);
int is_print(char c);

/**************PRINTALL***********/

int print_unprintable(va_list my_specs, char my_buff,
		int flg, int prcs, int wid, int size);
int print_reverse(va_list my_specs, char my_buff, int flg,
		int prcs, int wid, int size);
int print_rotstring(va_list my_specs, char my_buff, int size,
		int prcs, int wid, int flg);
int print_ptr(va_list my_specs, char my_buff,
		int size, int wid, int prcs, int flg);

int _printf(const char *format, ...);

#endif
