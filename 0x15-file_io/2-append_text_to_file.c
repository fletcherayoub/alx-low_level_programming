#include "main.h"
#include <string.h>
/**
 * append_text_to_file - appends the specified text to the file
 * @filename: the file to append
 * @text_content: comtent to append
 * Return: 1 succes, -1 failed
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int ld;

	if (filename == NULL)
		return (-1);

	ld = open(filename, O_WRONLY | O_APPEND);
	if (ld == -1)
		return (-1);

	if (text_content != NULL)
	{
		ssize_t bytes_written = write(ld, text_content, strlen(text_content));

		if (bytes_written == -1 || bytes_written != (ssize_t)strlen(text_content))
		{
			close(ld);
			return (-1);
		}
	}
	close(ld);
	return (-1);
}
