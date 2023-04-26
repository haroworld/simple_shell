#include "shell.h"

/**
 * _myenv - program to print the current environment
 * @info: the Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - program to get the value of an environ variable
 * @info: The Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *my_node = info->env;
	char *p;

	while (my_node)
	{
		p = starts_with(my_node->str, name);
		if (p && *p)
			return (p);
		my_node = my_node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - program to Initialize a new environment variable,
 *             or modify an existing one
 * @info: the Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - program to Remove an environment variable
 * @info: the Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int x;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (x = 1; x <= info->argc; x++)
		_unsetenv(info, info->argv[x]);

	return (0);
}

/**
 * populate_env_list - program to populates env linked list
 * @info: the Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
