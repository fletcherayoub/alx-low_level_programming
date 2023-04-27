#include "lists.h"
#include <stdio.h>

/**
 * print_list - print all the elements of a list
 * @h: pointer to a list
 * Return: number of nodes
 */

size_t print_list(const list_t *h)
{
	const list_t *temp = h;
	int index = 0;

	while (temp != NULL)
	{
		printf("[%d] ", temp->len);
		if (temp->str == NULL)
			printf("(nil)");
		else
			printf("%s", temp->str);
		printf("\n");
		temp = temp->next;
		index++;
	}
}
