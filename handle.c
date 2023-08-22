#include "main.h"
/**
 * write_no- this function prints a string
 * @is_neg: argument list
 * @my_buff: an array of characters
 * @wid: width
 * @size: size
 * @flg: the flags
 * @prcs: the precision specifier
 * @pnd: char types.
 */
int write_no(int is_neg, int pnd, char my_buff[], int flg,
		int prcs, int size, int wid)
{
	int len = BUFF_SIZE - pnd - 1;
	char bar = ' ', xtraC = 0;

	UNUSED(size);
	if ((flg & ZERO) && !(flg & SUB))
		bar = '0';
	if (is_neg)
		xtraC = '-';
	else if (flg & ADD)
		xtraC = '+';
	else if (flg & SPACE)
		xtraC = ' ';
	return (write_numb(pnd, my_buff, flg, prcs, wid, len,
			bar, xtraC));
}
/**
 * write_numb- this function writes a number
 * @my_buff: an array of characters
 * @wid: width
 * @flg: the flags
 * @prcs: the precision specifier
 * @pnd: char types.
 * @len: the number length
 * @xtraC: the extra character
 * @bar: the char for adding space
 * Return: the number of characters printed
 */
int write_numb(int pnd, char my_buff[], int flg,
		int prcs, int len, char xtraC, char bar, int wid)
{
	int x, bar_start = 1;

	if (prcs == 0 && pnd == BUFF_SIZE - 2 && my_buff[pnd]
			== '0' && wid == 0)
		return (0);
	if (prcs == 0 && pnd == BUFF_SIZE - 2 && my_buff[pnd] == '0')
	       my_buff[pnd] = bar = ' ';
	if (prcs > 0 && prcs < len)
		bar = ' ';
	while (prcs > len)
		my_buff[--pnd] = '0', len++;
	if (xtraC != 0)
		len++;
	if (wid > len)
	{
		for (x = 1; x < (wid - (len + 1)); x++)
			my_buff[x] = bar;
		my_buff[x] = '\0';
		if (flg & SUB && bar == ' ')
		{
			if (xtraC)
				my_buff[--pnd] = xtraC;
			return (write(1, &my_buff[pnd], len) + write(1,
						&my_buff[1], x - 1));
		}
		else if (!(flg & SUB && bar == ' '))
		{
			if (xtraC)
				my_buff[--pnd] = xtraC;
			return (write(1, &my_buff[1], x - 1) + write(1,
						&my_buff[pnd], len));
		}
		else if (!(flg & SUB) && bar == '0')
		{
			if (xtraC)
				my_buff[--bar_start] = xtraC;
			return (write(1, &my_buff[bar_start], x - bar_start) +
					write(1, &my_buff[pnd], len - (1 - bar_start)));
		}
	}
	if (xtraC)
		my_buff[--pnd] = xtraC;
	return (write(1, &my_buff[pnd], len));
}

/**
 * write_unsigned- this function prints an unsigned number
 * @is_neg: argument list
 * @my_buff: an array of characters
 * @wid: width
 * @size: size
 * @flg: the flags
 * @prcs: the precision specifier
 * @pnd: index
 * Return: number of printed characters
 */
int write_unsigned(int is_neg, int pnd, char my_buff[], int flg,
		int prcs, int wid, int size)
{
	int len = BUFF_SIZE - pnd - 1, x = 0;
	char bar = ' ';

	UNUSED(is_neg);
	UNUSED(size);

	if (prcs == 0 && pnd == BUFF_SIZE - 2 && my_buff[pnd] == '0')
		return (0);
	if (prcs > 0 && prcs < len)
		bar = ' ';
	while (prcs > len)
	{
		my_buff[--pnd] = '0';
		len++;
	}
	if ((flg & ZERO) && !(flg & SUB))
		bar = '0';
	if (wid > len)
	{
		for (x = 0; x < wid - len; x++)
			my_buff[x] = bar;
		my_buff[x] = '\0';
		if (flg & SUB)
		{
			return (write(1, &my_buff[pnd], len) + write(1,
						&my_buff[0], x));
		}
		else
		{
			return (write(1, &my_buff[0], x) + write(1,
						&my_buff[pnd], len));
		}
	}
	return (write(1, &my_buff[pnd], len));
}
/**
 * write_ptr- this function points to an address
 * @my_buff: an array of characters
 * @wid: width
 * @flg: the flags
 * @pnd: the index
 * @len: the number length
 * @xtraC: the extra character
 * @bar: the char for adding space
 * @bar_start: the first index
 * Return: the number of characters printed
 */
int write_ptr(char my_buff[], int pnd, int len,
		int wid, int flg,char bar, char xtraC, int bar_start)
{
	int x;

	if (wid > len)
	{
		for (x = 3; x < wid - len + 3; x++)
			my_buff[x] = bar;
		my_buff[x] = '\0';
		if (flg & SUB && bar == ' ')
		{
			my_buff[--pnd] = 'x';
			my_buff[--pnd] = '0';
			if (xtraC)
				my_buff[--pnd] = xtraC;
			return (write(1, &my_buff[pnd], len) + write(1,
						&my_buff[3], x - 3));
		}
		else if (!(flg & SUB) && bar == ' ')
		{
			my_buff[--pnd] = 'x';
			my_buff[--pnd] = '0';
			if (xtraC)
				my_buff[--pnd] = xtraC;
			return (write(1, &my_buff[3], x - 3) + write(1,
						&my_buff[pnd], len));
		}
		else if (!(flg & SUB) && bar == '0')
		{
			if (xtraC)
				my_buff[--bar_start] = xtraC;
			my_buff[1] = '0';
			my_buff[2] = 'x';
			return (write(1, &my_buff[bar_start], x - bar_start) +
					write(1, &my_buff[pnd], len - (1 - bar_start) - 2));
		}
	}
	my_buff[--pnd] = 'x';
	my_buff[--pnd] = '0';
	if (xtraC)
		my_buff[--pnd] = xtraC;
	return (write(1, &my_buff[pnd], BUFF_SIZE - pnd - 1));
}
/**
 * write_char- this function writes characters
 * @my_buff: an array of characters
 * @wid: width
 * @flg: the flags
 * @prcs: the precision specifier
 * @c: char types.
 * @size: the size
 * Return: the number of characters printed
 */
int write_char(int c, char my_buff[], int flg,
		int prcs, int size, int wid)
{
	int x = 0;
	char bar = ' ';

	UNUSED(prcs);
	UNUSED(size);

	if (flg & ZERO)
		bar = '0';
	my_buff[x++] = c;
	my_buff[x++] ='\0';

	if (wid > 1)
	{
		my_buff[BUFF_SIZE - 1] = '\0';
		for (; x < wid - 1; x++)
			my_buff[BUFF_SIZE - x - 2] = bar;
		if (flg & SUB)
			return (write(1, &my_buff[BUFF_SIZE - x - 1], wid - 1));
		else
			return(write(1, &my_buff[BUFF_SIZE - x - 1], wid - 1) +
					write(1, &my_buff[0], 1));
	}
	return (write(1, &my_buff[0], 1));
}
