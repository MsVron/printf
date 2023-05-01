#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _printf(const char *format, ...);
int print_integer(int n);
int print_binary(unsigned int n);
int print_unsigned(unsigned int n, int base, int uppercase);
int print_string(va_list args, char *buf, int pos);
int _to_hex(char *buf, unsigned int num);
int _strcpy(char *dest, char *src);
int _strlen(char *str);

#endif /* MAIN_H */
