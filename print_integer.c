#include "main.h"

/**
 *print_integer - prints an integer
 *@n: integer to be printed
 *
 *Return: number of digits printed
 */
int print_integer(long int n)
{
	unsigned int num, last_digit;
	int digit_count = 0;

	if (n == INT_MIN)
	{
		num = (unsigned int) - (n / 10);
		last_digit = (unsigned int) - (n % 10);
		_putchar('-');
		digit_count++;
		print_unsigned(num, 10, 0);
		digit_count += count_digits(num, 10);
		_putchar(last_digit + '0');
		digit_count++;
	}
	else
	{
		if (n < 0)
		{
			_putchar('-');
			digit_count++;
			num = (unsigned int) - n;
		}
		else
			num = (unsigned int) n;

		digit_count += print_unsigned(num, 10, 0);
	}

	return (digit_count);
}
