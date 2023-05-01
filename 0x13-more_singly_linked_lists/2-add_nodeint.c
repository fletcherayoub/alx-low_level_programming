#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * add_nodeint - add a new node at the beginning of a list
 * @head: adress of head
 * @n: integer
 *
 * Return: the adress of the new element
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *f;

	f = malloc(sizeof(listint_t));

	if (f == NULL)
		return (NULL);

	f->n = n;
	f->next = *head;
	*head = f;

	return (*head);
}
