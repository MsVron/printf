#include "main.h"

/**
 * _printf - prints formatted output to stdout
 * @format: a string containing zero or more directives to write to stdout
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);
	printed_chars = print_string_format(format, args);
	va_end(args);

	return (printed_chars);
}

/**
 * print_string_format - prints formatted output to stdout with variadic arguments
 * @format: a string containing zero or more directives to write to stdout
 * @args: a va_list of variadic arguments
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int print_string_format(const char *format, va_list args)
{
	int i = 0;
	int printed_chars = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printed_chars += print_directive(format[i], args);
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
		i++;
	}

	return (printed_chars);
}

/**
 * print_directive - prints the specified directive to stdout with variadic arguments
 * @directive: the directive to print to stdout
 * @args: a va_list of variadic arguments
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int print_directive(char directive, va_list args)
{
	switch (directive)
	{
		case 'c':
			return (_putchar(va_arg(args, int)));

		case 's':
			return (print_string(args));

		case '%':
			_putchar('%');
			return (1);

		case 'd':
		case 'i':
			return (print_integer(va_arg(args, int)));

		case 'b':
			return (print_binary(va_arg(args, unsigned int)));

		case 'u':
			return (print_unsigned(va_arg(args, unsigned int), 10, 0));

		case 'o':
			return (print_unsigned(va_arg(args, unsigned int), 8, 0));

		case 'x':
			return (print_unsigned(va_arg(args, unsigned int), 16, 0));

		case 'X':
			return (print_unsigned(va_arg(args, unsigned int), 16, 1));

		default:
			_putchar('%');
			_putchar(directive);
			return (2);
	}
}
