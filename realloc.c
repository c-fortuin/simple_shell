#include "shell.h"

/**
 * _memset - Fills memory with constant byte
 * @b: Byte
 * @n: Amount of bytes to fill
 * @s: Pointer
 * Return: Pointer to memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - Free a string
 * @pp: String
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		ffree(*pp++);
	free(a);
}

/**
 * _realloc - Realocate block of mememory
 * @ptr: Pointer
 * @new_sise: Size of new block
 * @old_size: Size of old block
 * Return: Pointer to block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
