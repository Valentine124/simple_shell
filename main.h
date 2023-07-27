#ifndef SHELL_H
#define SHELL_H

/* HEADER FILES */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "string.h"
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdarg.h>
#include "structures.h"

/* global variables */
extern char **environ;

/* END HEADER FILES */

/* FUNCTIONS */
void shell_non_interactive(char *program_name);
void shell_interactive(char *program_name);
char *read_line(void);
char **split_string(char *line);
int exec_cmd(char **argv, char *program_name);
int execute_child(char **argv, char *program_name);
char *find_path(char *cmd);
void free_list(dir_t *list);
void ctr_c_handler(int sig_int);
int _putchar(int fd, char c);
void print_str(int fd, char *str);
void print_num(int fd, int n);
void print_error(char *format, ...);
char *handle_incomplete_path(char *cmd, dir_t *list);
int handle_exit(char *program, char **argv);
int handle_builtin(char *program_name, char **argv);
int handle_env(char *program_name, char **argv);
int _atoi(char *str);

/* End of functins */


#endif
