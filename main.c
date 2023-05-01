#include "main.h"
#include <stdio.h>


/**
 *main - Entry point
 *
 *Return: Always 0
 */
int main(void)
{
    int len;
    char *str;

    len = _printf("%S", "No special character.");
    str = "No special character.No special character.";
    if (len != 42 || strcmp(_buffer, str) != 0)
        printf("Error: case 1\nGot: [%.*s]\nExpected: [%s]\n", len, _buffer, str);

    len = _printf("%S", "\n");
    str = "\x0A\x0A";
    if (len != 8 || strcmp(_buffer, str) != 0)
        printf("Error: case 2\nGot: [%.*s]\nExpected: [%s]\n", len, _buffer, str);

    len = _printf("%S", "\x01\x02\x03\x04\x05\x06\x07");
    str = "\x01\x02\x03\x04\x05\x06\x07\x01\x02\x03\x04\x05\x06\x07";
    if (len != 56 || strcmp(_buffer, str) != 0)
        printf("Error: case 3\nGot: [%.*s]\nExpected: [%s]\n", len, _buffer, str);

    len = _printf("Could you print some non-prntable characters?\n%S\nThanks!\n", "Sure:\x1F\x7F\n");
    str = "Could you print some non-prntable characters?\nSure:\x1F\x7F\x0A\nThanks!\n";
    if (len != 144 || strcmp(_buffer, str) != 0)
        printf("Error: case 4\nGot: [%.*s]\nExpected: [%s]\n", len, _buffer, str);

    return (0);
}
