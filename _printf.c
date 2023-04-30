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
	int i, printed_chars = 0;

	va_start(args, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			printed_chars++;
			continue;
		}

		switch (format[++i])
		{
			case 'c':
				_putchar(va_arg(args, int));
				printed_chars++;
				break;
			case 's':
				printed_chars += print_string(va_arg(args, char *));
				break;
			case 'd':
			case 'i':
				printed_chars += print_integer(va_arg(args, int));
				break;
			case 'b':
				printed_chars += print_binary(va_arg(args, unsigned int));
				break;
			case 'u':
				printed_chars += print_unsigned(va_arg(args, unsigned int));
				break;
			case '%':
				_putchar('%');
				printed_chars++;
				break;
			default:
				_putchar('%');
				_putchar(format[i]);
				printed_chars += 2;
		}
	}

	va_end(args);

	return (printed_chars);
}
