#include "main.h"

/**
 * size_numb- a function that converts a number to
 * a specific size
 * @numb: the number whose size is to be converted
 * @size: the number that tells the size to be converted
 * Return: the value of the conversion
 */

long int size_numb(long int numb, int size)
{
	if (size == LONGS)
		return (numb);
	else if (size == SHORTS)
		return ((short)numb);
	return ((int)numb);
}
