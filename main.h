#ifndef SHELL_H
#define SHELL_H

/* HEADER FILES */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "string.h"
#include <sys/wait.h>
#include <string.h>

/* END HEADER FILES */

/* FUNCTIONS */
void shell_non_interactive(char *program_name);
void shell_interactive(char *program_name);
char *read_line(void);
char **split_string(char *line);
void exec_cmd(char **argv, char *program_name);
void execute_child(char **argv, char *program_name);

/* End of functins */


#endif
