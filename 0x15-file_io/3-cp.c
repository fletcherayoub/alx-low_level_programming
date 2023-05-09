#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - a function that copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int f_to;
	int f_from;
	ssize_t read_l, write_l;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	f_from = open(argv[1], O_RDONLY);
	if (f_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't read drom file %s\n", argv[1]);
		exit(98);
	}
	f_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 00664);
	while ((read_l = read(f_from, buffer, 1024)) != 0)
	{
		if (f_to == -1)
		{
			dprintf(STDERR_FILENO, "Error: can't write to %s\n", argv[2]);
			exit(99);
		}
		if (read_l == -1)
		{
			dprintf(STDERR_FILENO, "Error: can't read from file %s\n"
					, argv[1]);
			exit(98);
		}
		write_l = write(f_to, buffer, read_l);
		if (write_l != read_l || write_l == -1)
		{
			dprintf(STDERR_FILENO, "Error: can't write to %s\n"
					, argv[2]);
			exit(99);
		}
	}
	if (close(f_from) == -1)
	{
		dprintf(STDERR_FILENO,"Error: can't close fd %d\n", f_from);
		exit(100);
	}
	if (close(f_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't close fd %d\n", f_to);
		exit(100);
	}
	return (0);
}
