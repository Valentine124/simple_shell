#include "string.h"

/**
 * _strlen - finds the length of a string
 * @s: The string
 * Return: Return lenth of the string
 */

int _strlen(char *s)
{
	int c = 0, len = 0;

	while (s[c++] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * _strcpy - copies a string to another
 * @dest: The string to copy from
 * @src: The string to copy to
 * Return: Return dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - concatinate two strings
 * @dest: The main string
 * @src: The string to add
 * Return: Returns dest
 */

char *_strcat(char *dest, char *src)
{
	int dest_len = _strlen(dest);
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';

	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: The first string
 * @s2: The second string
 * Return: Return 0 if s1 == s2 and any
 * other number if s1 != s2
 */

int _strcmp(char *s1, char *s2)
{
	int rem = 0, i = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		rem = s1[i] - s2[i];
		if (rem != 0)
		{
			return (rem);
		}
		i++;
	}

	return (rem);
}

/**
 * _strdup - Duplicates a string
 * @s: The string to duplicate
 * Return: Return a pointer to the
 * duplicate string or NULL
 */

char *_strdup(char *s)
{
	char *dup;
	int i;

	dup = malloc(sizeof(char) * (_strlen(s) + 1));

	if (dup == NULL)
		return (NULL);
	for (i = 0; s[i]; i++)
	{
		dup[i] = s[i];
	}
	dup[i] = '\0';

	return (dup);
}
