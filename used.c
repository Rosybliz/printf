#include "main.h"

/**
 * size_numb- a function that converts a number to
 * a specific size
 * @numb: the number whose size is to be converted
 * @size: the number that tells the size to be converted
 * Return: the value of the conversion
 */

long int size_numb(long int numb, int size)
{
	if (size == BIGSIZE)
		return (numb);
	else if (size == SMALLSIZE)
		return ((short)numb);
	return ((int)numb);
}
/**
 * my_digit - confirms if the character to be printed is digit
 * @A: The character to be checked
 * Return: return 0 on Success
 */
int my_digit(char A)
{
	if (A <= '9' && A >= '0')
		return(1);
	return (0);
}
/**
 * size_unsigned- a function that casts a number to a size
 * @numb: the number
 * @size: the size
 * Return: the new size
 */

long int size_unsigned(unsigned long int numb,  int size)
{
	if (size == SMALLSIZE)
		return ((unsigned short)numb);
	else if (size == BIGSIZE)
		return (numb);
	return ((unsigned int)numb);
}

/**
 * put_hexa- a funtion that appends ascii in hexadecimal form
 * @ascii: ASCII code
 * @my_buff: the character array
 * @x: index
 * Return: 3
 */
int put_hexa(char ascii, char my_buff[], int x)
{
	char map[] = "0123456789ABCDEF";

	if (ascii < 0)
		ascii *= -1;
	my_buff[x++] = '\\';
	my_buff[x++] = 'x';
	my_buff[x++] = map[ascii / 16];
	my_buff[x] = map[ascii % 16];

	return (3);
}
/**
 * is_print- a function that checks if a character is printable
 * @c: the character
 * Return: return 1
 */
int is_print(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
