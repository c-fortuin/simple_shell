#include "shell.h"

/**
 * **strtow - Splits string into words
 * @str: Input string
 * @d: Delimeter string
 * Return: Pointer to an array of strings, Fail - NULL
 */
char **strtow(char *str, char *d)
{
	int i;
	int m;
	int k;
	int j;
	int nw = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
	{
		d = " ";
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d
						|| !str[i + 1]))
				nw++;
		
