#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * insert_nodeint_at_index - inserts a new node at given position
 * @head: head of list
 * @idx: node in the list
 * @n: integer
 *
 * Return: adress
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int l;
	listint_t *ln;
	listint_t *h;

	h = *head;

	if (idx != 0)
	{
		for (l = 0; l < idx - 1 && h != NULL; l++)
		{
			h = h->next;
		}
	}

	if (h == NULL && idx != 0)
		return (NULL);

	ln = malloc(sizeof(listint_t));
	if (ln == NULL)
		return (NULL);

	ln->n = n;

	if (idx == 0)
	{
		ln->next = *head;
		*head = ln;
	}
	else
	{
		ln->next = h->next;
		h->next = ln;
	}
	return (ln);
}
