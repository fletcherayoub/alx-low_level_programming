#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * free_listint - free a list
 * @head: head of list
 *
 * Return: nothing
 */
void free_listint(listint_t *head)
{
	listint_t *nl;

	while ((nl = head) != NULL)
	{
		/*head in next node*/
		head = head->next;
		free(nl);
	}
}
