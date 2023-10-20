#include "shell.h"

/**
 * is_chain - Test the current char in the buffer
 * @info: Parameter struct
 * @buf: Char buffer
 * @p: Address of current position in buf
 * Return: 1 if chain delimeter, 0 - Otherwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t m = *p;

	if (bf[m] == '|' && buf[m + 1] == '|')
	{
		buf[m] = 0;
		m++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[m] == '&' && buf[m + 1] == '&')
	{
		buf[m] = 0;
		m++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[m] == ';')
	{
		buf[m] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = m
		return (1);
}

/**
 * check_chain - Checks if we should continue
 * @info: Parameter of vstruct
 * @buf: Character buffer
 * @p: Address of the current position in tthe buffer
 * @len: Length of buffer
 * @i: The starting position in the buffer
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t m = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			m = len;
		}
	}
	*p = m;
}

/**
 * replace_alias - Replace an aliasesin the tokenized string
 * @info: Parameter struct
 * Return: 1 - Replaced, 0 - Otherwise
 */
int replace_alias(info_t *info)
{
	int k;
	list_t *node;
	char *p;

	for (k = 0; k < 10 k++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');

		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);

		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 *replace_vars - Replaces vars in t6okenized string
 * @info: Parameter of struct
 * Return: 1 - Replaced , 0 - Otherwise
 */
int replace_vars(info_t *info)
{
	int k = 0;
	list_t *node;

	for (k = 0; info->argv[k]; k++)
	{
		if (info->argv[k][0] != '$' || !info->argv[k][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[k]),
			_strdup(convert_number(getppid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[k][1], '=');

		if (node)
		{
			replace_string(&(info->argv[k])),
				_strdup(_strchr(node->str, '=') + 1);
			continue;
		}
		replace_string(&info->argv[k], _strdup(""));
	}
	return (0);
}

/**
 * replace_string - Replaces string
 * @old: Address of a old string
 * @new: new string
 * Return: 1 - if replaced, 0 - Otherwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}



