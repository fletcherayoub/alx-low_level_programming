#include "main.h"
/**
 * firstfunction - returns 0 or 1
 * @num: number being checked
 * @f: factor of the number
 *
 * Return: 0 if not prime, 1 if prime
 */
int firstfunction(int num, int f)
{
	if (f < num)
	{
		if (num % f == 0)
		{
			return (0);
		}
		else
		{
			return (firstfunction(num, f + 1));
		}
	}
	else
	{
		return (1);
	}
}

/**
 * is_prime_number - checks if number is prime or not prime
 * @n: number to be checked
 *
 * Return: 1 if number is prime 0 if not prime
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	else
	{
		return (firstfunction(n, 2));
	}
}
