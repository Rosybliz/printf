#include "main.h"

/**
 * int_print- a function that prints integers
 * @my_specs: the variable list
 * @my_buff: an array of characters
 * @wid: width
 * @size: size
 * @flg: the flags
 * @prcs: the precision
 * Return: returns total number of characters printed
 */

int int_print(va_list my_specs, char my_buff[],
		int wid, int size, int flg, int prcs)
{
	int x = BUFF_SIZE - 2;
	int is_neg = 0;
	unsigned long int numb;
	long int y = va_arg(my_specs, long int);

	y = size_numb(y, size);

	if (y == 0)
		my_buff[x--] = '0';
	my_buff[BUFF_SIZE - 1] = '\0';
	numb = (unsigned long int)y;

	if (y < 0)
	{
		numb = (unsigned long int)((-1) * y);
		is_neg = 1;
	}
	while (numb > 0)
	{
		my_buff[x--] = (numb % 10) + '0';
		numb /= 10;
	}
	x++;
	return (write_no(is_neg, x, my_buff, flg, wid, prcs, size));
}
