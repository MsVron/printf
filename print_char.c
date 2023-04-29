#include "main.h"

/**
 *print_char - prints a character
 *@arg: the argument to print
 *Return: the number of characters printed
 */
int print_char(va_list arg)
{
	char c = va_arg(arg, int);
	_putchar(c);
	return (1);
}
