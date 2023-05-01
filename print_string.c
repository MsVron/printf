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
		if (str[i] < 32 || str[i] >= 127)
			pos += _strcpy(buf + pos, "\\x"), pos += _to_hex(buf + pos, str[i]);
		else
			buf[pos++] = str[i];
	}

	return (pos);
}
