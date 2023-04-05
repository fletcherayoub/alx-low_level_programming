#include "main.h"
/**
 * _lenght - checks the lenght of a string
 * @st: is the string
 * Return: return the leng of the string
 */
int _lenght(char *st)
{
	if (*st == '\0')
		return (0);
	return (1 + _lenght(st + 1));
}

/**
 * check_f - checks if the string is palindrome
 * @i: the index
 * @l: length of the string
 * @s: the string
 * Return: 1 if is polindrome or 0 if not
 */
int check_f(int i, int l, char *s)
{
	if (l > 0)
	{
		if (s[i] == s[l])
		{
			return (checkp(i + 1, l - 1, s));
		}
		else if (s[i] != s[l])
		{
			return (0);
		}
		else
		{
			return (1);
		}
	}
	return (1);
}

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: the string
 * Return: return 1 if the string is a palindrome or 0 otherwise
 */
int is_palindrome(char *s)
{
	return (checkp(0, _lenght(s) - 1, s));
}
