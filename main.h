#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int _printf(const char *format, ...);
int print_char(va_list types, char buffer[],
              int flags, int width, int precision, int size);
int print_str(va_list types, char buffer[],
             int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
             int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
                 int flags, int width, int precision, int size);

#endif /* MAIN_H */
