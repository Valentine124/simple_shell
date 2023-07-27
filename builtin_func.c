/****************
 * All built in functions are implemented here
 *
 * Example of built in is:
 * exit - to exit the shell
 * clear - to clear the console
 * env - to print enviroment variables etc.
 */

#include "main.h"

/**
 * handle_exit - exits the shell
 * @program: the exe file
 * @argv: the argument list
 *
 * Return: 0 or exit status
 */
int handle_exit(char *program, char **argv)
{
	(void)program;
	if (argv[1])
	{
		int n = _atoi(argv[1]);

		if (n < 0)
		{
			return (-1);
		}
		return (n);
	}
	else
	{
		return (0);
	}
}

/**
 * handle_env - print the environment variable
 * @program_name: the exe file
 * @argv: The argument list
 *
 * Return: -1
 */
int handle_env(char *program_name, char **argv)
{
	int i;

	(void)program_name;
	(void)argv;

	i = 0;

	while (environ[i])
	{
		print_str(STDOUT_FILENO, environ[i]);
		print_str(STDOUT_FILENO, "\n");

		i++;
	}

	return (-1);
}
