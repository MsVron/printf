#include "main.h"

/**
 *print_string - prints a string, replacing non-printable
 *               characters with escape sequences
 *@args: arguments list containing the string to print
 *@buf: buffer to print to
 *@pos: current position in the buffer
 *
 *Return: the new position in the buffer
 */
int print_string(va_list args, char *buf, int pos)
{
	char *str = va_arg(args, char *);
	int i, len;

	if (str == NULL)
		str = "(null)";

	len = _strlen(str);

	for (i = 0; i < len; i++)
	{
		if (str[i] < 32 || str[i] >= 127 || str[i] == '\\')
			pos += _strcpy(buf + pos, "\\x"), pos += _to_hex(buf + pos, str[i]);
		else
			buf[pos++] = str[i];
	}

	return (pos);
}

/**
 * _strlen - returns the length of a string
 * @str: the string to measure
 *
 * Return: the length of the string
 */
int _strlen(char *str)
{
    int len = 0;

    while (*str)
    {
        len++;
        str++;
    }

    return len;
}

/**
 * _strcpy - copies a string from src to dest
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: the length of the copied string
 */
int _strcpy(char *dest, char *src)
{
    int len = 0;

    while (*src)
    {
        *dest = *src;
        len++;
        dest++;
        src++;
    }

    return len;
}

/**
 * _to_hex - Converts an integer to its hexadecimal ASCII representation
 * @buf: A buffer to store the result
 * @num: The integer to convert
 * Return: The number of bytes written to buf
 */
int _to_hex(char *buf, unsigned int num)
{
    int i, len = 0;
    char hex[] = "0123456789abcdef";

    for (i = 0; num / 16; i++)
        buf[i] = hex[num % 16], num /= 16;

    buf[i] = hex[num % 16], len = i + 1;

    for (i = len; i < 2; i++)
        buf[i] = '0';

    for (i = 0; i < len / 2; i++)
    {
        buf[i] ^= buf[len - i - 1];
        buf[len - i - 1] ^= buf[i];
        buf[i] ^= buf[len - i - 1];
    }

    return len;
}
