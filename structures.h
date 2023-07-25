#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct node_dir - node that stores a directory
 * @name: name of directory
 * @next: pointer to the next directory in path
 *
 * Discription: This is a node represents each
 * directory in PATH environment variable
 */
typedef struct node_dir
{
	char *name;
	struct node_dir *next;
} dir_t;

/**
 * struct built_in - a data type for built in commands
 * @name: name of command
 * @func: a function pointer to the command handler
 */
typedef struct built_in
{
	char *name;
	void (*func)(char *);
} builtin_t;

#endif
