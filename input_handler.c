#include "main.h"

/**
 * read_line - read bytes from stdin
 *
 * Return: pointer to rhe string
 */

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		free(line);
		if (isatty(STDIN_FILENO))
			_putchar(STDOUT_FILENO, '\n');

		exit(EXIT_SUCCESS);
	}

	return (line);
}

/**
 * split_string - seperate a single string into array of strings
 * @line: string to split
 *
 * Return: pointer to the array of string
 */

char **split_string(char *line)
{
	char *token = NULL, *delim = " \n", *line_cpy = NULL;
	char **argv = NULL;
	int argc = 0, count;

	line_cpy = _strdup(line);

	token = strtok(line_cpy, delim);
	while (token)
	{
		argc++;
		token = strtok(NULL, delim);
	}
	argc++;

	argv = malloc(sizeof(char *) * argc);

	if (argv == NULL)
	{
		free(line_cpy);
		free(line);
		exit(EXIT_FAILURE);
	}

	count = 0;
	token = strtok(line, delim);
	while (token)
	{
		argv[count] = token;
		token = strtok(NULL, delim);
		count++;
	}
	argv[count] = NULL;
	free(line_cpy);

	return (argv);
}
