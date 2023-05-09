#include "main.h"

/**
 * create_file - a function that creates a file
 * @filename: file to be created
 * @text_content: content to be written
 * Return: 1 succes otherwise -1
 */
int create_file(const char *filename, char *text_content)
{
	int ld, n;
	ssize_t lw;

	if (filename == NULL)
		return (-1);
	ld = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0600);
	if (ld == -1)
		return (-1);
	if (text_content)
	{
		for (n = 0; text_content[n]; n++)
			;
		lw = write(ld, text_content, n);
		if (lw == -1)
			return (-1);
	}
	return (1);
}
