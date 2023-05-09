#include "main.h"
#define B_SIZE 1024

/**
 * main - a function that copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success if failed Error
 */

int main(int argc, char **argv)
{
	char *ln[B_SIZE];
	int f_from, f_to;
	ssize_t lread, lwrite;

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	if (argv[1] == NULL)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1])
			, exit(98);
	if (argv[2] == NULL)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2])
			, exit(99);

	f_from = open(argv[1], O_RDONLY);
	f_to = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	lread = read(f_from, ln, B_SIZE);
	if (lread == -1)
		dprintf(STDERR_FILENO, "Error: can't read from file %s\n", argv[1])
			, exit(98);
	while (lread != 0)
	{
		lwrite = write(f_to, ln, lread);
		if (lwrite == -1)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2])
				, exit(99);
		lread = read(f_from, ln, B_SIZE);
		if (lread == -1)
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1])
				, exit(98);
	}
	f_from = close(f_from);
	if (f_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f_from)
			, exit(100);
	f_to = close(f_to);
	if (f_to == -1)
		dprintf(STDERR_FILENO, "Error: can't close fd %d\n", f_to)
			, exit(100);
	return (0);
}
