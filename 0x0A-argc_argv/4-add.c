#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

/**
 * main - program that adds positive numbers
 * @argc: number of command
 * @argv: array
 *
 * Return: 1 if not integer , 0 otherwise
 */

int main(int argc, char *argv[])
{
	int n, m, len, sum;
	char *ptr;

	if (argc < 2)
		printf("0\n");
	else
	{
		sum = 0;
		for (n = 1; n < argc; n++)
		{
			ptr = argv[n];
			len = strlen(ptr);

			for (m = 0; m < len; m++)
			{
				if (isdigit(*(ptr + m)) == 0)
				{
					printf("error\n");
					return (1);
				}
			}
			sum += atoi(argv[n]);
		}
	printf("%d\n", sum);
	}
	return (0);
}
