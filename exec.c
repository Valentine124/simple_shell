#include "main.h"

/**
 * exec_cmd - execute the command and arguments
 * @argv: the argument vector
 * @program_name: the name of the exec file
 */

void exec_cmd(char **argv, char *program_name)
{
	if (argv == NULL || argv[0] == NULL)
		return;

	if (handle_builtin(program_name, argv[0]) == 1)
		return;

	execute_child(argv, program_name);
}

/**
 * execute_child - execute of binary in a new process
 * @argv: the array of strings
 * @program_name: name of th exe file
 */

void execute_child(char **argv, char *program_name)
{
	static int c;
	char *cmd = find_path(argv[0]);
	pid_t pid;

	c = 0;

	c += 1;

	if (!cmd)
	{
		print_error("%s: %d: %s: not found\n", program_name, c, argv[0]);
		return;
	}

	pid = fork();

	if (pid == -1)
	{
		perror(program_name);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(cmd, argv, NULL) == -1)
		{
			perror(program_name);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
