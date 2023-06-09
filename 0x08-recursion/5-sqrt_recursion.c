#include "main.h"
/**
 * firstfunction - checks if sqrt of number exists
 * @num: number
 * @psqrt: poissible sqrt of number
 *
 * Return: sqrt of number -1 for error
 */
int firstfunction(int num, int psqrt)
{
	if ((psqrt * psqrt) == num)
	{
		return (psqrt);
	}
	else
	{
		if ((psqrt * psqrt) > num)
			return (-1);
		else
			return (firstfunction(num, psqrt + 1));
	}
}
/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: number to calculate the square
 *
 * Return: squareroot of n
 * -1 if n does not have a natural sqrt
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	else
		return (firstfunction(n, 0));
}
