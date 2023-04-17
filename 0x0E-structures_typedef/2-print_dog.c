#include "dog.h"
#include <stdio.h>

/**
 * print_dog - print a struct dog
 * @d: the struct dog
 */
void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		if (d->owner == NULL)
			printf("owner: %p\n", (void *)d->owner);
		else
			printf("owner: %s\n", d->owner);
		if (d->name == NULL)
			printf("name: %p\n", (void *)d->name);
		else
			printf("name: %s\n", d->name);
		printf("age: %f\n", d->age);
	}
}
