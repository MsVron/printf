#include "main.h"

/**
 *print_number - prints a number
 *@n: the number to print
 *@base: the base of the number
 *@digits: the digits to use
 *Return: the number of characters printed
 */
int print_number(unsigned int n, unsigned int base, char *digits)
{
	unsigned int count = 0;

	if (n >= base)
		count += print_number(n / base, base, digits);

	_putchar(digits[n % base]);
	count++;

	return (count);
}
