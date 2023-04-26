#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_integer(int n);
int _print_binary(unsigned int n);
int print_unsigned(unsigned int n, int base, int uppercase);
int print_string(va_list arg);
int print_pointer(void *ptr);
int handle_flags(char *flags, char specifier, va_list args);

#endif /* MAIN_H */
