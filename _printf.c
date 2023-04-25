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

int _print_binary(unsigned int n)
{
	int count = 0;

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
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++; /*skip the % */
			switch (*format)
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;

				case 's':
					{
						char *s = va_arg(args, char *);
						if (s == NULL)
							s = "(null)";
						for (; *s != '\0'; s++)
							count += _putchar(*s);
						break;
					}

				case 'd':
				case 'i':
					{
						int n = va_arg(args, int);
						if (n < 0)
						{
							count += _putchar('-');
							n = -n;
						}

						count += print_integer(n);
						break;
					}

				case 'b':
					{
						unsigned int n = va_arg(args, unsigned int);
						count += _print_binary(n);
						break;
					}

				case '%':
					count += _putchar('%');
					break;

				default:
					count += _putchar('%');
					count += _putchar(*format);
					break;
			}
		}
		else
		{
			count += _putchar(*format);
		}

		format++;
	}

	va_end(args);

	return (count);
}

/*
 *print_integer - prints an integer to stdout
 *@n: the integer to print
 *
 *Return: the number of characters printed
 */

int print_integer(int n)
{
	int count = 0;

	if (n / 10)
		count += print_integer(n / 10);

	count += _putchar(n % 10 + '0');

	return (count);
}
