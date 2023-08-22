#include "main.h"
#include <stdarg.h>
/**
 */
int print_specifiers(const char *format, ...)
{
	va_list argument_list;
	va_start(argument_list, format);
	int my_argument = 0;

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
				return -1;
			switch (*format)
			{
				case 'd':
				{
					int variadic4 = va_arg(argument_list, int);
					write(1, &variadic4, 1);
					my_argument++;
					break;
				}
				case 'i':
				{
					int variadic5 = va_arg(argument_list, int);
					my_argument++;
					break;
				}
				default:
					break;
			}
		}
		format++;
	}
	va_end(argument_list);
	return (my_argument++);
}


