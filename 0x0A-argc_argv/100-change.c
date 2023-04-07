#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * converter - function that does all the mathematics
 * @n: variable from main
 * Return: the number of coins needed
 */

int converter(int n)
{
	int count = 0;

	while (n != 0)
	{
		if (n % 10 == 9 || n % 10 == 7)
			n -= 2;
		else if (n % 25 == 0)
			n -= 25;
		else if (n % 10 == 0)
			n -= 10;
		else if (n % 5 == 0)
			n -= 5;
		else if (n % 2 == 0)
		{
			if (n % 10 == 6)
				n -= 1;
			else
				n -= 2;
		}
		else
			n -= 1;
		count++;
	}
	return (count);
}

/**
 * main - coin count
 * @argc: command line
 * @argv: array
 *
 * Return: 0 if exactly 1 argument is passed
 */

int main(int argc, char *argv[])
{
	int n, coin;

	coin = 0;

	if (argc != 2)
	{
		printf("error\n");
		return (1);
	}
	n = atoi(argv[1]);

	if (n < 0)
		printf("0\n");
	else
	{
		coin = converter(n);
		printf("%d\n", coin);
	}
	return (0);
}
