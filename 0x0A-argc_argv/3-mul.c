#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main - prints the multiplication of two integers
 * @argc: argument count
 * @argv: array with argument
 *
 * Return: 0 if true 1 if false
 */

int main(int argc, char *argv[])
{
	int n = 0, m = 0;

	if (argc == 3)
	{
		n = atoi(argv[1]);
		m = atoi(argv[2]);
		printf("%d\n", n * m);
	}
	else
	{
		printf("error\n");
		return (1);
	}
	return (0);
}
