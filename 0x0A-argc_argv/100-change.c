#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * converter - change coins for an amount money
 * @argc: number of arg
 * @argv: array with arg
 *
 * Return: 0
 */

int converter(int argc, char *argv[])
{
	int n = 0, m = 0;
	char c[] = "Error";

	if (argc != 2)
	{
		printf("%s\n", c);
		return (1);
	}
	n = atoi(argv[1]);
	while (n >= 25)
	{
		n -= 25;
		m++;
	}
	while (n >= 10)
	{
		n -= 10;
		m++;
	}
	while (n >= 5)
	{
		n -= 5;
		m++;
	}
	while (n >= 2)
	{
		n -= 2;
		m++;
	}
	if (n == 1)
		m++;
	printf("%d\n", m);
	return (0);
}
