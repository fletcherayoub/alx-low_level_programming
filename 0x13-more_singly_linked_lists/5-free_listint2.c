#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * free_listint2 - a function that frees the list
 * @head: pointer
 *
 * Return: nothing
 */
void free_listint2(listint_t **head)
{
	listint_t *nl, *nm;

	if (head != NULL)
	{
		nl = *head;

		while ((nm = nl) != NULL)
		{

		nl = nl->next;

	free(nm);
		}
	*head = NULL;
	}
}
