#include "main.h"
#include <limits.h>

/**
 * print_integer - Prints an integer to stdout.
 * @n: The integer to print.
 *
 * Return: The number of digits printed.
 */
int print_integer(int n)
{
    int count = 0;
    int is_negative = 0;

    if (n == INT_MIN)
    {
        count += _putchar('-');
        n = -(n + 1);
        is_negative = 1;
    }

    if (n < 0)
    {
        count += _putchar('-');
        n = -n;
        is_negative = 1;
    }

    if (n / 10 != 0)
        count += print_integer(n / 10);

    count += _putchar((n % 10) + '0');

    if (is_negative)
        count++;

    return (count);
}
