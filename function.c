#include "main.h"

/**
 * printUnsigned- a function that prints an unsigned number
 * @my_specs: the argument list
 * @my_buff: the character array
 * @flg: the flags
 * @prcs: the precision
 * @wid: the width
 * @size: the size
 * Return: number of characters printed
 */
int printUnsigned(va_list my_specs, char my_buff[], int flg, int wid,
		int prcs, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(my_specs, unsigned long int);

	numb = size_unsignd(numb, size);

	if (numb == 0)
		my_buff[x--] = '0';
	my_buff[BUFF_SIZE - 1] = '\0';
	while (numb > 0)
	{
		my_buff[x--] = (numb % 10) + '0';
		numb /= 10;
	}
	x++;
	return (write_unsignd(0, x, my_buff, flg, wid, prcs, size));
}
/**
 * printOctal- a function that prints a base 8 number
 * @my_specs: the argument list
 * @my_buff: the character array
 * @flg: the flags
 * @prcs: the precision
 * @wid: the width
 * @size: the size
 * Return: number of characters printed
 */
int printOctal(va_list my_specs, char my_buff[], int flg, int wid, int prcs,
		int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(my_specs, unsigned long int);
	unsigned long int i_numb = numb;

	UNUSED(wid);

	numb = size_unsignd(numb, size);
	if (numb == 0)
		my_buff[x--] = '0';
	while (numb > 0)
	{
		my_buff[x--] = (numb % 8) + '0';
		numb /= 8;
	}
	if (flg & P_HASH && i_numb != 0)
		my_buff[x--] = '0';
	x++;
	return (write_unsignd(0, x, my_buff, flg, wid, prcs, size));
}
/**
 * printHexa- a function that prints an unsigned number in hexadecimal
 * @my_specs: the argument list
 * @my_buff: the character array
 * @flg: the flags
 * @prcs: the precision
 * @wid: the width
 * @size: the size
 * Return: number of characters printed
 */
int printHexa(va_list my_specs, char my_buff[], int flg, int wid, int prcs,
		int size)
{
	return (print_hexa(my_specs, "0123456789abcdef", my_buff, flg, 'x',
				wid, prcs, size));
}
/**
 * printHexaUp- a function that prints an unsigned number
 * in upper hexadecimal
 * @my_specs: the argument list
 * @my_buff: the character array
 * @flg: the flags
 * @prcs: the precision
 * @wid: the width
 * @size: the size
 * Return: number of characters printed
 */
int printHexaUp(va_list my_specs, char my_buff[], int flg, int wid, int prcs,
		int size)
{
	return (print_hexa(my_specs, "0123456789ABCDEF", my_buff, flg, 'X',
				wid, prcs, size));
}
/**
 * print_hexa- a function that prints a number
 * in lower or upper hexadecimal
 * @my_specs: the argument list
 * @my_buff: the character array
 * @flg: the flags
 * @prcs: the precision
 * @wid: the width
 * @size: the size
 * @flg_c: the
 * @map: the --
 * Return: number of characters printed
 */
int print_hexa(va_list my_specs, char map[], char my_buff[], int flg,
		char flg_c, int wid, int prcs, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(my_specs, unsigned long int);
	unsigned long int i_numb = numb;

	UNUSED(wid);

	numb = size_unsignd(numb, size);

	if (numb == 0)
		my_buff[x--] = '0';
	my_buff[BUFF_SIZE - 1] = '\0';
	while (numb > 0)
	{
		my_buff[x--] = map[numb % 16];
		numb /= 16;
	}
	if (flg & P_HASH && i_numb != 0)
	{
		my_buff[x--] = flg_c;
		my_buff[x--] = '0';
	}
	x++;
	return (write_unsignd(0, 1, my_buff, flg, wid, prcs, size));
}
