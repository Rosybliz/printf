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

/********* WRITES*************/

int write_char(int c, char my_buff[], int flg,
		int prcs, int size, int wid)
int write_ptr(int pnd, char my_buff[], int flg,
		int len, char xtraC, char bar, int bar_start, int wid)
int write_unsigned(int is_neg, int pnd, char my_buff, int flg,
		int prcs, int wid, int size)
int write_numb(int pnd, char my_buff[], int flg,
		int prcs, int len, char xtraC, char bar, int wid)
int write_no(int is_neg, int pnd, char my_buff[], int flg,
		int prcs, int size, int wid)

int _printf(const char *format, ...);

#endif
