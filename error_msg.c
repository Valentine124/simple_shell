#include "main.h"

/**
 * print_error - print error message to stderr
 * @format: A formatted string
 */
void print_error(char *format, ...)
{
	int i, n;
	char *str;
	va_list param;

	va_start(param, format);

	for (i = 0; format[i]; i++)
	{
		if (i != 0 && format[i - 1] == '%')
			continue;

		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 's':
					str = va_arg(param, char *);
					print_str(STDERR_FILENO, str);
					break;
				case 'd':
					n = va_arg(param, int);
					print_num(STDERR_FILENO, n);
					break;
				default:
					return;
			}
			continue;
		}

		_putchar(STDERR_FILENO, format[i]);
	}

	va_end(param);
}
