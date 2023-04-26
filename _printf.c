#include "main.h"
#define BUFFER_SIZE 1024

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

/**
 * print_buffer - Prints buffer and resets index
 * @buffer: buffer to print
 * @count: pointer to count of characters printed
 *
 * Return: void
 */
void print_buffer(char *buffer, int *count)
{
    int i;

    for (i = 0; i < *count; i++)
        _putchar(buffer[i]);

    /* Reset count to 0 */
    *count = 0;
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
    int i, j, count = 0;
    char *s;
    char buffer[BUFFER_SIZE];

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;

            switch (format[i])
            {
                case 'c':
                    buffer[count] = (char) va_arg(args, int);
                    count++;
                    break;
                case 's':
                    s = va_arg(args, char *);
                    for (j = 0; s[j] != '\0'; j++)
                    {
                        buffer[count] = s[j];
                        count++;
                        if (count == BUFFER_SIZE)
                        {
                            print_buffer(buffer, &count);
                        }
                    }
                    break;
                default:
                    buffer[count] = '%';
                    count++;
                    buffer[count] = format[i];
                    count++;
                    break;
            }
        }
        else
        {
            buffer[count] = format[i];
            count++;
        }

        if (count == BUFFER_SIZE)
        {
            print_buffer(buffer, &count);
        }
    }

    print_buffer(buffer, &count);

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
