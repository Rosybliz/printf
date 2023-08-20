#include "main.h"
/**
 * _printf-  function that produces an output according to the
 * printf format
 * @format: The character string
 * Return: Returns the number of characters printed
 */
int _printf(const char *format, ...)
{
	int my_argument = 0;
	va_list argument_list;

	va_start(argument_list, format);
	if (format == NULL)
		return (-1);
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
				return (-1);

			switch (*format)
			{
				case 's':
				{
					char *variadic2 = va_arg(argument_list, char*);

					write(1, variadic2, strlen(variadic2));
					my_argument += strlen(variadic2);
					break;
				}
				case 'c':
				{
					char variadic1 = va_arg(argument_list, int);

					write(1, &variadic1, 1);
					my_argument++;
					break;
				}
				case '%':
				{
					write(1, format, 1);
					my_argument++;
					break;
				}
				default:
				{
					break;
				}
		}
			format++;
		}
		va_end(argument_list);
	}
	return (my_argument);

}

