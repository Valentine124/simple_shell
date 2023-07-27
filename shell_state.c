#include "main.h"

/**
 * shell_interactive - handle interactive mode
 * @program_name: name of the exec file
 */

void shell_interactive(char *program_name)
{
	char *line = NULL;
	char **argv = NULL;
	int status = -1;

	while (status == -1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		line = read_line();
		argv = split_string(line);

		status = exec_cmd(argv, program_name);

		free(line);
		free(argv);

		if (status >= 0)
			exit(status);
	}
}

/**
 * shell_non_interactive - handle non-interactive mode
 * @program_name: name of exec file
 */

void shell_non_interactive(char *program_name)
{
	char *line = NULL;
	char **argv = NULL;
	int status = -1;

	while (status == -1)
	{
		line = read_line();
		argv = split_string(line);

		status = exec_cmd(argv, program_name);

		free(line);
		free(argv);

		if (status >= 0)
			exit(status);
	}
}
