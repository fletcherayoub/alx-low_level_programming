#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - free linked list
 * @head: the head
 *
 * Return: no return
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t fr = 0;
	long int lm;

	while (head)
	{
		lm = head - head->next;
		fr++;
		printf("[%p] %d\n", (void *)head, head->n);
		if (lm > 0)
			head = head->next;
		else
		{
			printf("-> [%p] %d\n", (void *)head->next, head->next->n);
			break;
		}
	}
	return (fr);
}
