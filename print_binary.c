#include "main.h"

/*
 *print_binary - prints an unsigned int in binary
 *@n: the unsigned int to print
 *
 *Return: the number of characters printed
 */

int print_binary(unsigned int n)
{
	int count = 0;

	if (n == 0)
		return (_putchar('0'));

	if (n / 2)
		count += print_binary(n / 2);

	count += _putchar(n % 2 + '0');

	return (count);
}
