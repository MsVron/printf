#include "main.h"

int print_integer(int n);

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

/*
 *_printf - produces output according to a format
 *@format: character string containing zero or more directives
 *
 *Return: the number of characters printed
 *(excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	
	int count = 0;
	
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c': 
					count += _putchar(va_arg(args, int)); 
					break;
				case 's':
				{
					char *s = va_arg(args, char*);
					if (!s) s = "(null)";
					while (*s) count += _putchar(*s++);
					break;
				}
				case 'd': case 'i': 
					count += print_integer(va_arg(args, int)); 
					break;
				case 'b': 
					count += _print_binary(va_arg(args, unsigned int)); 
					break;
				case 'u': 
					count += print_unsigned(va_arg(args, unsigned int), 10, 0); 
					break;
				case 'o': 
					count += print_unsigned(va_arg(args, unsigned int), 8, 0); 
					break;
				case 'x': 
					count += print_unsigned(va_arg(args, unsigned int), 16, 0); 
					break;
				case 'X': 
					count += print_unsigned(va_arg(args, unsigned int), 16, 1); 
					break;
				case 'S': 
					count += print_string(va_arg(args, char*)); 
					break;
				case '%': 
					count += _putchar('%'); 
					break;
				default: 
					count += _putchar('%') + _putchar(*format); 
					break;
			}
		}
		else {
			count += _putchar(*format);
		}
		format++;
	}

	va_end(args);
	return count;
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
 *print_string - Prints a string and handles non-printable characters
 *@str: The string to print
 *
 *Return: The number of characters printed
 */
int print_string(char *str)
{
	int count = 0;

	for (; *str != '\0'; str++)
	{
		if (*str < 32 || *str >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += print_unsigned(*str, 16, 1);
		}
		else
		{
			count += _putchar(*str);
		}
	}

	return (count);
}

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
