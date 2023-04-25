#include "main.h"
#include <stdarg.h>

/**
 *_printf - produces output according to a format.
 *@format: character string containing directives.
 *
 *Return: number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	char c, *s;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);
					_putchar(c);
					count++;
					break;

				case 's':
					s = va_arg(args, char *);
					if (s == NULL)
						s = "(null)";
					while (*s)
					{
						_putchar(*s);
						s++;
						count++;
					}

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

	va_end(args);

	return count;
}
