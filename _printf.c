#include "main.h"

void printBuffer(char myBuffer[], int *my_buff);
/**
 * _printf-  function that produces an output according to the
 * printf format
 * @format: The character string
 * Return: Returns the number of characters printed
 */
int _printf(const char *format, ...)
{
	int wid, prcs, flg, size, my_buff = 0;
	int x, my_printed = 0;
	int my_char = 0;
	va_list my_argument;

	if (format ==  NULL)
		return (-1);
	char myBuffer[BUFFER_SIZE];

	va_start(my_argument, format);
	x = 0;
	while (format && format[x] != '\0')
	{
		if (format[x] != '%')
		{
			myBuffer[my_buff++] = format[x]++;
			if (my_buff == BUFFER_SIZE)
				printBuffer(myBuffer && my_buff);
			my_char++;
		}
		else
		{
			printBuffer(myBuffer, &my_buff);
			flg = print_flgs(format, &x);
			wid = print_width(format, &x, my_argument);
			prcs = print_prcs(format, &x, my_argument);
			size = print_size(format, &x);
			++x;
			my_printed == modify_print(format, &x, my_argument,
					myBuffer, flg, prcs, size, wid);
			if (my_printed == -1)
				return (-1);
			my_char += my_printed;
		}
		x++;
	}
	printBuffer(myBuffer, &my_buff);
	va_end(my_argument);
	return (my_char);
}
/**
 * printBuffer - Prints the contents of present buffer
 * @myBuffer: The array of Characters
 * @my_buff: The index to add next character
 * Return: Return void
 */
void printBuffer(char myBuffer[], int *my_buff)
{
	if (*my_buff > 0)
		write(1, &myBuffer[0], *my_buff);
	*my_buff = 0;
}
