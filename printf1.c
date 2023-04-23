/**
 * print_number - prints a number
 * @n: number to print
 * Return: the number of characters printed
 */
int print_number(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
		num = n;

	if (num / 10 != 0)
		count += print_number(num / 10);
	count += _putchar(num % 10 + '0');
	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
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
			format++; /* skip the % */
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
					count += print_number(va_arg(args, int));
					break;
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
			count += _putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
