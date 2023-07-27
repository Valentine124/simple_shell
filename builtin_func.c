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
 * @program_name: the exe file
 */
void handle_exit(char *program_name)
{
	(void)program_name;

	exit(0);
}

/**
 * handle_env - print the environment variable
 * @program_name: the exe file
 */
void handle_env(char *program_name)
{
	int i;

	(void)program_name;

	i = 0;

	while (environ[i])
	{
		print_str(STDOUT_FILENO, environ[i]);
		print_str(STDOUT_FILENO, "\n");

		i++;
	}
}
