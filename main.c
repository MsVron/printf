#include "main.h"

/**
 *main - Entry point
 *
 *Return: Always 0
 */
int main(void)
{
    char *str1 = "hello, world!";
    char *str2 = "This is a string.";
    char *str3 = "This is another string.";
    char *str4 = "The value of pi is approximately 3.14159265359.";
    char *str5 = "The quick brown fox jumps over the lazy dog.";

    _printf("%s\n", str1);
    _printf("%s\n", str2);
    _printf("%s\n", str3);
    _printf("%s\n", str4);
    _printf("%s\n", str5);

    return 0;
}
