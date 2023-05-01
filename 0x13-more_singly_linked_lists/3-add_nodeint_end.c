#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * add_nodeint_end - add a new node at the end of a list
 * @head: head of a list
 * @n: integer
 *
 * Return: adress
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *f, *q;

	f = malloc(sizeof(listint_t));
	if (f == NULL)
		return (NULL);

	f->n = n;
	f->next = NULL;
	q = *head;
	if (*head == NULL)
		*head = f;
	else
	{
		while (q)
		{
			if (q->next == NULL)
			{
				q->next = f;
				break;
			}
			else
				q = q->next;
		}
	}
	return (f);
}

