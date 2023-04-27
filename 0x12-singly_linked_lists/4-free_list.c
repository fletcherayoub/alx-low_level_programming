#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_list - free a list_t list
 * @head: parameter
 *
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *n = head;
	list_t *next;

	while (n != NULL)
	{
		next = n->next;
		if (n->str != NULL)

			free(n->str);
		free(n);

		n = next;
	}
}
