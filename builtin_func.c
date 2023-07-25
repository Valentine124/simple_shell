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
