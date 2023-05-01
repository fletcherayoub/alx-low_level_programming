#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * delete_nodeint_at_index - deletes the node at index
 * @head: head of a list
 * @index: index of the list where node deleted
 *
 * Return: 1 if it succeded, -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int n;
	listint_t *ln, *next;

	ln = *head;

	if (index != 0)
	{
		for (n = 0; n < index - 1 && ln != NULL; n++)
		{
			ln = ln->next;
		}
	}

	if (ln == NULL || (ln->next == NULL && index != 0))
	{
	return (-1);
	}
next = ln->next;

if (index != 0)
{
	ln->next = next->next;
	free(next);
}
else
{
	free(ln);
	*head = next;
}
return (1);
}
