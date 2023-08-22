#include "main.h"
/**
 * printCharacter - Prints character
 * @myBuffer: Array to take printing
 * @my_specs: arguments
 * @wid: The width
 * @size: The size specifier
 * @prcs: Specifies precision
 * @flg: Handles the flags
 * Return: Return number of character printed
 */
int printCharacter(va_list my_specs, char myBuffer[],
		int wid, int size, int prcs, int flg)
{
	char c = va_arg(my_specs, int);

	return (write_no(c, wid, myBuffer, size, prcs, flg, 1));
}

/**
 * printString - Prints a String
 * @myBuffer: Takes arrays
 * @my_specs: arguments
 * @wid: The width
 * @size: Size specifier
 * @prcs: Specifies Precision
 * @flg: Handles flags
 * Return: return number of strings printed
 */
int printString(va_list my_specs, char myBuffer[],
		int wid, int size, int prcs, int flg)
{
	int my_len = 0;
	char *ptr = va_arg(my_specs, char*);

	UNUSED(myBuffer);
	UNUSED(flg);
	UNUSED(wid);
	UNUSED(prcs);
	UNUSED(size);

	if (ptr == NULL)
	{
		ptr = "(NULL)";
		if (prcs >= 7)
			ptr = " ";
	}
	while (ptr[my_len] != '\0')
		my_len++;
	if (prcs < my_len && prcs > 0)
		prcs = my_len;
	if (my_len < wid)
	{
		int x;

		if (SUB && flg)
		{
			write(1, &ptr[0], my_len);
			x = wid - my_len;

			while (x > 0)
				x--;
			return (wid);
		}
		else
		{
			for (x = wid - my_len; x > 0; x--)
				write(1, " ", 1);
			write(1, &ptr[0], my_len);
			return (wid);
		}
	}
	return (write(1, ptr, my_len));
}


/**
 * printPercent - Prints percent
 * @myBuffer: Takes arrays
 * @my_specs: Arguments
 * @wid: The width
 * @size: Size specifier
 * @prcs: Specifies Precision
 * @flg: Handles flags
 * Return: Number of percent printed
 */

int printPercent(va_list my_specs, char myBuffer[],
		int wid, int size, int prcs, int flg)
{
	UNUSED(my_specs);
	UNUSED(myBuffer);
	UNUSED(wid);
	UNUSED(size);
	UNUSED(prcs);
	UNUSED(flg);

	return (write(1, "%%", 1));
}
