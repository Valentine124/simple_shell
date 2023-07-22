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

	execute_child(argv, program_name);
}

/**
 * execute_child - execute of binary in a new process
 * @argv: the array of strings
 * @program_name
 */

void execute_child(char **argv, char *program_name)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(program_name);
			free(argv);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
