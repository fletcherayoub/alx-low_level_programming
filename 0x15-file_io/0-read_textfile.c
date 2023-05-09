#include "main.h"

/**
 * read_textfile - reads a text file and prints to the posix standard output
 * @filename: the name of the file
 * @letters: max number to get
 *
 * Return: actual number
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int lf, lin_read, lin_write;
	char *ln;

	if (filename == NULL)
		return (0);

	lf = open(filename, O_RDONLY);
	if (lf == -1)
		return (0);

	ln = malloc(sizeof(char) * (letters + 1));
	if (ln == NULL)
	{
		close(lf);
		return (0);
	}

	lin_read = read(lf, ln, letters);
	if (lin_read == -1)
	{
		close(lf);
		free(ln);
		return (0);
	}

	ln[lin_read] = '\0';

	lin_write = write(STDOUT_FILENO, ln, lin_read);
	if (lin_write == -1 || (size_t)lin_write != (size_t)lin_read)
	{
		close(lf);
		free(ln);
		return (0);
	}

	close(lf);
	free(ln);

	return (lin_read);
}
