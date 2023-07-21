#ifndef STRING_H
#define STRING_H

/* HEADER FILE */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/* END HEADER FILE */

/* Begining of function prototype */

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *s);

/* End of function prototypes */

#endif
