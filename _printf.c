#include "main.h"

/*
 *_putchar - writes a character to stdout
 *@c: the character to print
 *
 *Return: the number of characters printed
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/*
 *_print_binary - prints an unsigned int in binary
 *@n: the unsigned int to print
 *
 *Return: the number of characters printed
 */

/*
 *_print_binary - prints an unsigned int in binary
 *@n: the unsigned int to print
 *
 *Return: the number of characters printed
 */

int _print_binary(unsigned int n)
{
	int count = 0;

	if (n == 0)
		return (_putchar('0'));

	if (n / 2)
		count += _print_binary(n / 2);

	count += _putchar(n % 2 + '0');

	return (count);
}

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

/**
 *_printf - printf function
 *@format: the format string
 *Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int count = 0;

	va_start(arg, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')
				break;

			switch (*format)
			{
				case 'c':
					count += print_char(arg);
					break;
				case 's':
					count += print_string(arg);
					break;
				case 'd':
					count += print_number(va_arg(arg, int), 10, "0123456789");
					break;
				case 'x':
					count += print_number(va_arg(arg, unsigned int), 16, "0123456789abcdef");
					break;
				case 'X':
					count += print_number(va_arg(arg, unsigned int), 16, "0123456789ABCDEF");
					break;
				case 'u':
					count += print_unsigned(va_arg(arg, unsigned int), 10, 0);
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}

		format++;
	}

	va_end(arg);

	return (count);
}
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
