#include "main.h"

/**
 *print_string - prints a string
 *@arg: the argument to print
 *Return: the number of characters printed
 */

int print_string(va_list arg)
{
	char *str = va_arg(arg, char *);
	int len = 0;

	if (str == NULL)
		str = "(null)";

	while (str[len])
	{
		_putchar(str[len]);
		len++;
	}

	return (len);
}
