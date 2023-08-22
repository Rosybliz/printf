#include "main.h"
/**
 * print_flgs - This prints number of active flags
 * @format: Formated string to print arguments
 * @x: takes int parametes
 * Return: return flag on success
 */
int print_flgs(const char *format, int *x)
{
	int z;
	int y;
	int flg = 0;

	const char flags[] = {'+', '-', '0', '#', ' ', '\0'};
	const int flg_array[] = {SUB, ADD, ZERO, P_HASH, SPACE, 0};

	y = *x + 1;
	while (format[y] != '\0')
	{
		while (flags[z])
		{
			if (format[y] == flags[z])
			{
				flg |= flg_array[z];
				break;
			}
			z++;
			if (flags[z] == 0)
				break;
		}
		y++;
	}
	*x = y - 1;
	return (flg);
}
