#include "main.h"

/**
 * handle_builtin - handles all built in commands
 * @program_name: name of exe file
 * @builtin_name: The name of the built in command
 *
 * Return: 1 if built in exist else 0
 */
int handle_builtin(char *program_name, char *builtin_name)
{
	int i;

	builtin_t builtins[] = {
		{"exit", handle_exit},
		{NULL, NULL}
	};

	for (i = 0; builtins[i].name; i++)
	{
		if (_strcmp(builtins[i].name, builtin_name) == 0)
		{
			builtins[i].func(program_name);
			return (1);
		}
	}

	return (0);
}
