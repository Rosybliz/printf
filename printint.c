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
		int flg, int wid, int prcs, int size)
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

/**
 * printBinary- a function that prints positive integers
 * @my_specs: the variable list
 * @my_buff: an array of characters
 * @wid: width
 * @size: size
 * @flg: the flags
 * @prcs: the precision
 * Return: returns total number of characters printed
 */

int printBinary(va_list my_specs, char my_buff[],
		int flg, int wid, int prcs, int size)
{
	unsigned int j, k, x, sum;
	unsigned int b[32];
	int count;

	UNUSED(my_buff);
	UNUSED(flg);
	UNUSED(wid);
	UNUSED(prcs);
	UNUSED(size);

	j = va_arg(my_specs, unsigned int);
	k = 2147483648;
	b[0] = j / k;

	for (x = 1; x < 32; x++)
	{
		k /= 2;
		b[x] = (j / k) % 2;
	}
	for (x = 0, sum = 0, count = 0; x < 32; x++)
	{
		sum = sum + b[x];
		if (sum || x == 31)
		{
			char y = '0' + b[x];

			write(1, &y, 1);
			count++;
		}
	}
	return (count);
}



