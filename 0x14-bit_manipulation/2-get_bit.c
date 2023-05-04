#include "main.h"

/**
 * get_bit - Return the value of a bit at given index
 * @n: the number
 * @index: to get the value
 *
 * Return: if an error occurs -1 or the value of bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
if (index >= (8 * (sizeof(unsigned long int))))
return (-1);
return ((n >> index) & 1);
}
