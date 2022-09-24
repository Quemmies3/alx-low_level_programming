#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: input string.
 * Return: the pointer to dest.
 */

char *leet(char *s)
{
	int i = 0, ii;

	char leet[8] = {'O', 'L', '?', 'E', 'A', '?', '?', 'T'};

	while (s[i])
	{
		for (ii = 0; ii <= 7; ii++)
		{
			if (s[i] == leet[ii] ||
				s[i] - 32 == leet[ii])
				s[i] = ii + '0';
		}
		i++;
	}

	return (s);
}
