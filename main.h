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
#define P_HASH 8
#define ADD 2
#define BIGSIZE 2
#define SMALLSIZE 1
#define SPACE 16
#define UNUSED(x) (void)(x)
/********* WRITES*************/

int write_char(int c, char my_buff[], int flg,
		int prcs, int size, int wid);
int write_unsignd(int is_neg, int pnd, char my_buff[], int flg,
		int prcs, int wid, int size);
int write_numb(int pnd, char my_buff[], int flg,
		int prcs, int len, char xtraC, char bar, int wid);
int write_no(int is_neg, int pnd, char my_buff[], int flg,
		int prcs, int size, int wid);
int write_ptr(char my_buff[], int pnd, int len, int wid, int flg, char bar,
		char xtraC, int bar_start);
/*************USED************/
int my_digit(char A);
long int size_numb(long int numb, int size);
int put_hexa(char ascii, char my_buff[], int x);
long int size_unsignd(unsigned long int numb,  int size);
int is_print(char c);

/**************PRINTALL***********/

int print_unprintable(va_list my_specs, char my_buff[],
		int flg, int prcs, int wid, int size);
int print_reverse(va_list my_specs, char my_buff[], int flg,
		int prcs, int wid, int size);
int print_rotstring(va_list my_specs, char my_buff[], int size,
		int prcs, int wid, int flg);
int print_ptr(va_list my_specs, char my_buff[],
		int flg, int wid, int prcs, int size);
/***************FUNC***************/
/*int printCharacter(va_list my_specs, char myBuffer[],
                char* wid, int size, int prcs, int flg);*/
int printString(va_list my_specs, char myBuffer[],
		int wid, int size, int prcs, int flg);
int printPercent(va_list my_specs, char myBuffer[],
		int wid, int size, int prcs, int flg);

int printBinary(va_list my_specs, char my_buff[],
		int wid, int size, int flg, int prcs);

int print_flgs(const char *format, int *x);
int print_size(const char *format, int *x);
int print_width(const char *format, int *x, va_list my_argument);
int print_prcs(const char *format, int *x, va_list my_arguments);
int int_print(va_list my_specs, char my_buff[],
		int wid, int size, int flg, int prcs);


int _printf(const char *format, ...);



/************MYFUNCS*************/
int printCharacter(va_list my_specs, char myBuffer[],
		int wid, int size, int prcs, int flg);
int printString(va_list my_specs, char myBuffer[],
		int wid, int size, int prcs, int flg);
int printPercent(va_list my_specs, char myBuffer[],
		int wid, int size, int prcs, int flg);
/**
 * struct fptr - The structure
 * @fptr: format in this case
 * @fn: The asscociated function
 */
struct fptr
{
	char fptr;
	int(*fn)(va_list, char [], int, int, int, int);
};

/**
 * typedef struct fptr fptr_t - The structure
 * @fptr: The format
 * @fptr_t: function Associated
 */
typedef struct fptr fptr_t;

int _printf(const char *format, ...);
int modify_print(const char *fptr, int x, va_list my_argument,
		char myBuffer[], int flg, int prcs, int wid, int size);


/************MODIFIEDPRINT********************/
void printBuffer(char myBuffer[], int *my_buff);
int printUnsigned(va_list my_specs, char my_buff[], int flg, int size,
		int prcs, int wid);

int print_hexa(va_list my_specs, char map[],char my_buff[], int flg,
		char flg_c, int wid, int prcs, int size);
int printHexaUp(va_list my_specs, char my_buff[], int flg, int size, int prcs,
		int wid);
int printOctal(va_list my_specs, char my_buff[], int flg, int size, int prcs,
		int wid);
int printHexa(va_list my_specs, char my_buff[], int flg, int size, int prcs,
		int wid);


#endif
