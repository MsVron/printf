#include "main.h"

/**
 *_printf - prints formatted output to stdout
 *@format: a string containing zero or more directives to write to stdout
 *
 *Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	int i = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			switch (format[i])
			{
				case 'c':
					printed_chars += _putchar(va_arg(args, int));
					break;

				case 's':
					printed_chars += print_string(args);
					break;

				case '%':
					printed_chars += _putchar('%');
					break;

				case 'd':
				case 'i':
					printed_chars += print_integer((long int) va_arg(args, int));
					break;

				case 'b':
					printed_chars += print_binary(va_arg(args, unsigned int));
					break;

				case 'u':
					printed_chars += print_unsigned(va_arg(args, unsigned int), 10, 0);
					break;

				case 'o':
					printed_chars += print_unsigned(va_arg(args, unsigned int), 8, 0);
					break;

				case 'x':
					printed_chars += print_unsigned(va_arg(args, unsigned int), 16, 0);
					break;

				case 'X':
					printed_chars += print_unsigned(va_arg(args, unsigned int), 16, 1);
					break;

				default:
					_putchar('%');
					_putchar(format[i]);
					printed_chars += 2;
					break;
			}
		}
		else
		{
			printed_chars += _putchar(format[i]);
		}

		i++;
	}

	va_end(args);

	return (printed_chars);
}
