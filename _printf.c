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

/*
 *_printf - produces output according to a format
 *@format: character string containing zero or more directives
 *
 *Return: the number of characters printed
 *(excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
    int count = 0;  // move declaration to the top
    va_list arg_list;
    const char *str;
    int num, i, n;

    va_start(arg_list, format);

    for (str = format; *str; str++)
    {
        if (*str != '%')
        {
            _putchar(*str);
            count++;
            continue;
        }

        switch (*++str)
        {
            case 'c':
                _putchar(va_arg(arg_list, int));
                count++;
                break;
            case 's':
                for (i = 0, str = va_arg(arg_list, char *); str[i]; i++)
                {
                    _putchar(str[i]);
                    count++;
                }
                break;
            case '%':
                _putchar('%');
                count++;
                break;
            case 'd':
            case 'i':
                num = va_arg(arg_list, int);
                if (num < 0)
                {
                    _putchar('-');
                    count++;
                    num = -num;
                }
                n = print_number(num, 10, "0123456789");
                count += n;
                break;
            case 'o':
                num = va_arg(arg_list, unsigned int);
                n = print_number(num, 8, "01234567");
                count += n;
                break;
            case 'x':
                num = va_arg(arg_list, unsigned int);
                n = print_number(num, 16, "0123456789abcdef");
                count += n;
                break;
            case 'X':
                num = va_arg(arg_list, unsigned int);
                n = print_number(num, 16, "0123456789ABCDEF");
                count += n;
                break;
            default:
                _putchar('%');
                _putchar(*str);
                count += 2;
                break;
        }
    }

    va_end(arg_list);
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
