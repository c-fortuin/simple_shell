#include "shell.h"

/**
 * _strlen - Returns the length of a string
 * @s: String
 * Return: Int length of the string
 */
int _strlen(char *s)
{
	int k = 0;

	if (!s)
		return (0);

	while (*s++)
		k++;

	return (k);
}

/**
 * _strcmp - Lexicogarphic comparison of 2 strings
 * @s1: First
 * @s2: Second
 * Return: Neg if s1 < s2, Pos of s1 > s2 , 0 if s1 = s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - If needle starts with haystack
 * @needle: Substring
 * @haystack: String
 * Return: Address of next character of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*neeedle++ != *haystack++)
			return (NULL);
				return ((char *)haystack);
}

/**
 * _strcat - Concate 2 strings
 * @src: Source buffer
 * @dest: Destination buffer
 * Return: Pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	char *rtn = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;

	*dest = *src;
	return (rtn);
}
