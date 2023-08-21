#include "main.h"
/**
 * modify_print - Function to print arguments
 * @fptr: Formatted string to print the argument
 * @mnd: index
 * @my_argument: The list of argument to print
 * @myBuffer: Buffer array
 * @flg: The Flags
 * @prcs: Specifies the precision
 * @size: Specifies the size
 * @wid: Width
 * Return: Return positive value
 */
int modify_print(const char *fptr, int mnd, va_list my_argument,
		char myBuffer[], int flg, int prcs, int size, int wid)
{
	int x, fin_len = 0;
	int my_chars = -1;

	fptr_t fptr_types[] = {
		{'c', printCharacter}, {'s', printString}, {'%', printPercent}

	};
	for (x = 0; fptr_types[x].fptr != '\0'; x++)
	{
		if (fptr[*mnd] == fptr_types[x].fptr)
		{
			return (fptr_types[x].fptr(my_argument, myBuffer,
						flg, wid, prcs, size));
		}
	if (fptr_types[x].fptr == '\0')
		return (-1);
	fin_len += write(1, "%%", 1);
	if (fptr[*mnd - 1] == ' ')
		fin_len += write(1, " ", 1);
	else if (wid)
	{
		--(*mnd);
		while (fptr[*mnd] != ' ' && fptr[*mnd] != '%')
			--(*mnd);
		if (fptr[*mnd] == ' ')
			--(*mnd);
		return (1);
	}
	fin_len += write(1, &fptr[*mnd], 1);
	return (my_chars);

