#include "main.h"

/**
 *print_unsigned - prints an unsigned int to stdout
 *@n: the unsigned int to print
 *@base: the base to use for printing (8 for octal, 10 for decimal, 16 for hex)
 *@uppercase: 1 if the letters in hex should be uppercase, 0 if they should be lowercase
 *
 *Return: the number of characters printed
 */
int print_unsigned(unsigned int n, int base, int uppercase)
{
	int count = 0, i = 0;
	char buf[1024];
	char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (n == 0)
	{
		return (_putchar('0'));
	}

	while (n != 0)
	{
		buf[i++] = digits[n % base];
		n /= base;
	}

	while (i > 0)
	{
		count += _putchar(buf[--i]);
	}

	return (count);
}
