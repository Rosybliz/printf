#include "main.h"
/**
 * print_width - records the width to be printed
 * @x: Argument to be printed
 * @my_argument: the list of arguments
 * Return: Return width
 * @format: The formatted string to be printed
 */
int print_width(const char *format, int *x, va_list my_argument)
{
	int y = *x + 1;
	int wid = 0;

	while (format[y] != '\0')
	{
		if (my_digit(format[y]))
		{
			wid = wid * 10;
			wid = wid + format[y] - '0';
		}
		else if (format[y] == '*')
		{
			y++;
			wid = va_arg(my_argument, int);
			break;
		}
		else
			break;
		y++;
	}
	*x = y - 1;
	return (wid);
}
