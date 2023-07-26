#include "main.h"

/**
 * path_list - get the list of all diretory in path
 * @path: the value of the PATH environment variable
 *
 * Return: The list of directories in PATH
 */
dir_t *path_list(char *path)
{
	dir_t *head = NULL;
	dir_t *tail = NULL;

	char *dir = strtok(path, ":");

	while (dir)
	{
		dir_t *new = malloc(sizeof(dir_t));

		new->name = _strdup(dir);
		new->next = NULL;

		if (!head)
		{
			head = new;
			tail = head;
		}
		else
		{
			tail->next = new;
			tail = new;
		}

		dir = strtok(NULL, ":");
	}

	return (head);
}

/**
 * find_path - checks if a command is in the list of directories
 * in the PATH environment variable
 * @cmd: The command as string
 *
 * Return: The absolute path name
 */
char *find_path(char *cmd)
{
	struct stat buff;
	char *path = NULL, *path_cpy = NULL;
	dir_t *list;

	path_cpy = _strdup(getenv("PATH"));
	list = path_list(path_cpy);

	path = handle_incomplete_path(cmd, list);

	if (path[0])
	{
		free(path_cpy);
		return (path);
	}

	free(path_cpy);

	if (stat(cmd, &buff) == 0)
		return (cmd);

	return (NULL);
}

/**
 * handle_incomplete_path - handles the incomplete path cmd
 * @cmd: the command
 * @list: The list of paths
 *
 * Return: A pointer to the complete path or NULL
 */
char *handle_incomplete_path(char *cmd, dir_t *list)
{
	static char path[1024];
	struct stat buff;
	dir_t *temp;

	temp = list;

	while (temp)
	{
		_strcpy(path, temp->name);
		_strcat(path, "/");
		_strcat(path, cmd);
		_strcat(path, "\0");

		if (path[0] == '\0')
		{
			free_list(list);
			return (NULL);
		}

		if (stat(path, &buff) == 0)
		{
			free_list(list);
			return (path);
		}

		temp = temp->next;
	}

	path[0] = '\0';
	free_list(list);

	return (path);
}
