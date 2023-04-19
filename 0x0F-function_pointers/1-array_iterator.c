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
	if (action == NULL || array == NULL)
		return;
	while (size-- > 0)
	{
		action(*array);
		array++;
	}
}
