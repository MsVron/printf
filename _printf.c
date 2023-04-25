#include "main.h"

/*
 * _putchar - writes a character to stdout
 * @c: the character to print
 *
 * Return: the number of characters printed
 */
int _putchar(char c)
{
  return (write(1, &c, 1));
}

/*
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
          {
            int num = va_arg(args, int);
            int div = 1;
            if (num < 0)
            {
              count += _putchar('-');
              num *= -1;
            }
            while (num / div >= 10)
              div *= 10;
            while (div != 0)
            {
              int digit = num / div;
              count += _putchar('0' + digit);
              num %= div;
              div /= 10;
            }
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
