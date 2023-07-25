#include "main.h"

/**
 * free_list - free all memory allocated for the list
 * @list: The list
 */
void free_list(dir_t *list)
{
	if (list->next)
		free_list(list->next);

	free(list->name);
	free(list);
	list = NULL;
}

/**
 * ctr_c_handler - handle SIGINT signal
 * @sig_int: signal interrupt
 */
void ctr_c_handler(int sig_int)
{
	(void)sig_int;

	signal(SIGINT, ctr_c_handler);
	write(STDOUT_FILENO, "\n$ ", 3);
	fflush(stdout);
}
