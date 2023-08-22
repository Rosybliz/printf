#include "main.h"
/**
 * print_size - A function that prints size
 * @format: The formated string to be printed
 * @x: The list of argument
 * Return: Return size on Success
 */
int print_size(const char *format, int *x)
{
	int y = *x + 1;
	int size = 0;

	if (format[y] == 'l')
		size = BIGSIZE;
	else if (format[y] == 'h')
		size = SMALLSIZE;

	if (size == 0)
		*x = y - 1;
	else
		*x = y;
	return (size);
}
