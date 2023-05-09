#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * main - check code
 * @argc: arg count
 * @argv: arg vactor
 * Return: 0 success otherwise failed
 */

int main(int argc, char **argv)
{
	int lf;

	if (argc != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}

	lf = open(argv[1], O_RDONLY);
	if (lf == -1)
	{
		write(STDERR_FILENO, "Error: can't read from file\n", 28);
		exit(98);
	}
	exit(98);
}
