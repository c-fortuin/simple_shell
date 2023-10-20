#include "shell.h"

/**
 * _strcpy - Copies a string
 * @dest: Destination
 * @src: Source
 * Return: Pointer to the destination
 */
char *_strcpy(har *dest, char *src)
{
	int k = 0;

	if (dest == src || src == 0)
		return (dest);

	while (src[k])
	{
		dest[k] = src[k];
		k++;
	}
	dest[k] = 0;
	return (dest);
}

/**
 * _strdup - Duplicates a string
 * @str: String
 * Return: Pointer to duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *rtn;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;

	rtn = malloc(sizeof(char) * (length + 1));

	if (!rtn)
		return (NULL);

	for (length++; length--;)
	{
		rtn[lenght] = *--str;
	}

	return (rtn);
}

/**
 * _puts - Prints an input string
 * @str: String
 * Return: Nothing
 */
void _puts(char *str)
{
	int k = 0;

	if (!str)
		return;

	while (str[k] != '\0')
	{
		_putchar(str[k]);
		k++;
	}
}

/**
 * _putchar - Writes character c to stdout
 * @c: Character to print
 * Return: 1 -Success, -1 -Error
 */
int _putchar(char c)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(1, buf, k);
		k = 0;
	}

	if (c != BUF_FLUSH)
	       buf[k++] = c;

	return (1);
}
