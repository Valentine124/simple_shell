#include "main.h"

/**
 * _putchar - write a char to a file discriptor
 * @fd: file discriptor
 * @c: The character
 *
 * Return: The numbers of byte written
 */
int _putchar(int fd, char c)
{
	return (write(fd, &c, 1));
}

/**
 * print_str - Prints a string to a file discriptor
 * @fd: file discriptor
 * @str: The string to print
 */
void print_str(int fd, char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		_putchar(fd, str[i]);
}

/**
 * print_num - print a number to a file discriptor
 * @fd: file discriptor
 * @n: The number
 */
void print_num(int fd, int n)
{
	if ((n / 10) != 0)
		print_num(fd, n / 10);

	_putchar(fd, (n % 10) + '0');
}
