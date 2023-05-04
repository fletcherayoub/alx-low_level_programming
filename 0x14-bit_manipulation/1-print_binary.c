#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_binary - printd the binary representation of number
 * @nthe number for print
 *
 * Return: value
 */
void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);

	_putchar((n & 1) + '0');
}
