#include "main.h"
/**
 * _printf -  function that produces an output according to the
 * printf format
 * @format: The character string
 * Return: Returns the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int my_argument = 0;
	va_list argument_list;

	va_start(argument_list, format);
	if (format == NULL)
		putchar(-1);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			my_argument++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			if (*format == 's')
			{
				char size_str[39];
				int digit_length = 0;
				int length = 0;
				int st_length = 0;
				char *variadic2 = va_arg(argument_list, char*);

				while (variadic2[st_length] != '\0')
					st_length++;
				write(1, variadic2, st_length);
				my_argument = my_argument + st_length;

				/*char size_str[];*/
				length = st_length;
				/*int digit_length = 0;*/

				while (length > 0)
				{
					size_str[digit_length] = '0' + (length % 10);
					length = length / 10;
					digit_length++;
				}

				for (i = digit_length - 1; i > 0; i--)
				{
					write(1, &size_str[i], 1);
					my_argument++;
				}
			}
			else if (*format == 'c')
			{
				char variadic1 = va_arg(argument_list, int);

				write(1, &variadic1, 1);
				my_argument++;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				my_argument++;
			}
		}
		format++;
	}
	va_end(argument_list);
	return (my_argument);
}

