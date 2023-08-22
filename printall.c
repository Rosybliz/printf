#include "main.h"
/**
 * print_ptr- a function that prints the value of a pointer
 * @my_specs: my argument list
 * @my_buff: character array
 * @flg: flags
 * @wid: the width
 * @prcs: the precision
 * @size: the size
 * Return: returns number of characters printed
 */
int print_ptr(va_list my_specs, char my_buff[],
		int size, int wid, int prcs, int flg)
{
	char xtraC = 0, bar = ' ';
	int pnd = BUFF_SIZE - 2, len = 2, bar_start = 1;
	void *address = va_arg(my_specs, void *);
	char map[] = "0123456789abcdef";
	unsigned long num_a;

	UNUSED(wid);
	UNUSED(size);
	UNUSED(prcs);
	if (address == NULL)
		return (write(1, "(nil)", 5));
	my_buff[BUFF_SIZE - 1] = '\0';
	num_a = (unsigned long)address;
	while (num_a > 0)
	{
		my_buff[pnd--] = map[num_a % 16];
		num_a /= 16;
		len++;
	}
	if ((flg & ZERO) && !(flg & SUB))
		bar = '0';
	if (flg & ADD)
		xtraC = '+', len++;
	else if (flg & SPACE)
		xtraC = ' ', len++;
	pnd++;
	return (write_ptr(my_buff, pnd, len, bar, wid, bar, xtraC, bar_start));
}

/**
 * print_rotstring- a function that prints rot13 string
 * @my_specs: my argument list
 * @my_buff: character array
 * @flg: flags
 * @wid: the width
 * @prcs: the precision
 * @size: the size
 * Return: returns number of characters printed
 */
int print_rotstring(va_list my_specs, char my_buff[], int size,
		int prcs, int wid, int flg)
{
	char i;
	unsigned int x, k;
	char *str;
	int count;
	char to[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char fro[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(my_specs, char *);

	UNUSED(flg);
	UNUSED(my_buff);
	UNUSED(prcs);
	UNUSED(size);
	UNUSED(wid);

	if (str == NULL)
		str = "(AHYY)";
	for (x = 0; str[x]; k++)
	{
		for (k = 0; to[k]; k++)
		{
			if (to[k] == str[x])
			{
				i = fro[k];
				write(1, &i, 1);
				count++;
				break;
			}
		}
		if (!to[k])
		{
			i = str[x];
			write(1, &i, 1);
			count++;
		}
	}
	return (count);
}


/**
 * print_reverse- a function that prints values in reverse
 * @my_specs: my argument list
 * @my_buff: character array
 * @flg: flags
 * @wid: the width
 * @prcs: the precision
 * @size: the size
 * Return: returns number of characters printed
 */
int print_reverse(va_list my_specs, char my_buff[], int flg,
		int prcs, int wid, int size)
{
	char *str;
	int x;
	int count = 0;

	UNUSED(size);
	UNUSED(flg);
	UNUSED(wid);
	UNUSED(my_buff);

	str = va_arg(my_specs, char *);

	if (str == NULL)
	{
		UNUSED(prcs);

		str = ")Null(";
	}
	for (x = 0; str[x]; x++)
		;
	for (x = x - 1; x >= 0; x++)
	{
		char y = str[x];

		write(1, &y, 1);
		count++;
	}
	return (count);
}
/**
 * print_unprintable- a function that prints ASCII codes of characters
 * @my_specs: my argument list
 * @my_buff: character array
 * @flg: flags
 * @wid: the width
 * @prcs: the precision
 * @size: the size
 * Return: returns number of characters printed
 */
int print_unprintable(va_list my_specs, char my_buff[],
		int flg, int prcs, int wid, int size)
{
	int x = 0, offset = 0;
	char *str = va_arg(my_specs, char *);

	UNUSED(prcs);
	UNUSED(flg);
	UNUSED(size);
	UNUSED(wid);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[x] != '\0')
	{
		if (is_print(str[x]))
			my_buff[x + offset] = str[x];
		else
			offset = offset + put_hexa(str[x], my_buff,
					x + offset);
		x++;
	}
	my_buff[x + offset] = '\0';
	return (write(1, my_buff, x + offset));
}

