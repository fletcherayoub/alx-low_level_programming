#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - create new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 *
 * Return: n , NULL if faild
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *n;

	n = malloc(sizeof(dog_t));
	if (n == NULL)
		return (NULL);
	if (owner == NULL)
	{
		free(name);
		free(n);
		return (NULL);
	}
	if (name == NULL)
	{
		free(owner);
		free(n);
		return (NULL);
	}
	n->name = name;
	n->age = age;
	n->owner = owner;
	return (n);
}

