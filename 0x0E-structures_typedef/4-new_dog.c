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
	dog_t *dog;
	unsigned int i, dname, downer;

	if (name == NULL || owner == NULL)
		return (NULL);
	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);
	for (dname = 0; name[dname]; dname++)
		;
	dname++;
	dog->name = malloc(dname * sizeof(char));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}
	for (i = 0; i < dname; i++)
		dog->name[i] = name[i];
	dog->age = age;
	for (downer = 0; owner[downer]; downer++)
		;
	downer++;
	dog->owner = malloc(downer * sizeof(char));
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}
	for (i = 0; i < downer; i++)
		dog->owner[i] = owner[i];
	return (dog);
}
