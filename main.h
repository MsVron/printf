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

#endif /* MAIN_H */
