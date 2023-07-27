#include "main.h"

/**
 * handle_builtin - handles all built in commands
 * @program_name: name of exe file
 * @argv: The argument list
 *
 * Return: 1 if built in exist else 0
 */
int handle_builtin(char *program_name, char **argv)
{
	int i;

	builtin_t builtins[] = {
		{"exit", handle_exit},
		{"env", handle_env},
		{NULL, NULL}
	};

	for (i = 0; builtins[i].name; i++)
	{
		if (_strcmp(builtins[i].name, argv[0]) == 0)
		{
			return (builtins[i].func(program_name, argv));
		}
	}

	return (-1);
}
