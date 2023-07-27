#include "main.h"

/**
 * _atoi - convert ascii to int
 * @str: pointer to char
 *
 * Return: the int repesentation or -1
 */
int _atoi(char *str)
{
	int c, num = 0, sign = 1;

	if (str == NULL)
		return (num);

	for (c = 0; str[c]; c++)
	{
		if (str[c] == '-')
			sign *= -1;
		if (str[c] == '+')
			sign *= +1;
		else
		{
			if (str[c] >= '0' && str[c] <= '9')
				num = (num * 10) + (str[c] - 48);
			else
				return (-1);
		}
	}

	return (sign * num);
}
