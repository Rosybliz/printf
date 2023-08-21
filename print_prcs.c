#include "main.h"
/**
 * print_prcs - Function to print precision
 * @format: The fromatted string to be printed
 * @x: arguments to be printed
 * @my_arguments: The list of arguments to be printed
 * Return: Returns precision
 */
int print_prcs(const char *format, int *x, va_list my_arguments)
{
	int prcs = -1;
	int y = *x + 1;

	if (format[y] != '.')
		return (prcs);

	for (y = y + 1; format[y] != '\0'; y++)
	{
		if (my_digit(format[y]))
		{
			prcs = prcs * 10;
			prcs = prcs + format[y] - '0';
		}
		else if (format[y] == '*')
		{
			y++;
			prcs = va_arg(my_argument, int);
			break;
		}
		else
			break;
	}
	*x = y - 1;
	return (prcs);
}
