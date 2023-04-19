#include "function_pointers.h"

/**
 * array_iterator - executes a function giver as a parameter on
 * each element of an array
 * @array: execute function
 * @size: size of array
 * @action: function to be executed
 *
 * Return: 0
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int n = 0;

	if (action == NULL || array == NULL)
	{
	for (; n < size; n++)
	{
		action(array[n]);
	}
	}
}
