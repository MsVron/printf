#include "main.h"

/**
 *print_integer - Prints an integer to stdout
 *@n: The integer to print
 *
 *Return: The number of digits printed
 */
int print_integer(int n)
{
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		n = -n;
	}

	if (n / 10 != 0)
		count += print_integer(n / 10);

	count += _putchar((n % 10) + '0');

	return (count);
}
