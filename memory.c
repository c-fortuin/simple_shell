#include "shell.h"
/**
 * bfree - Free a pointer
 * @ptr: Address of pointer
 * Return: 1 freed, 0 Otherwise
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
