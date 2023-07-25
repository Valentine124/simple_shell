#include "main.h"

/**
 * main - the enttry point for the simple shell project
 * @argc: the argument count
 * @argv: the argument vector
 *
 * Discription: A command line interpreter that receives
 * an input from the user and respond according to the
 * input of the leader.
 * Example: ls will display the and folders in the
 * current working directory
 *
 * Return: Always 0 (Success);
 */

int main(int argc, char **argv)
{
	(void)argc;

	signal(SIGINT, ctr_c_handler);

	if (isatty(STDIN_FILENO))
	{
		/* Shell is interactive, display a prompt */
		shell_interactive(argv[0]);
	}
	else
	{
		/* Shell is non-interactive, do not display a prompt */
		shell_non_interactive(argv[0]);
	}

	return (0);
}
