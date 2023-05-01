#include "main.h"
#include <stdio.h>


/**
 *main - Entry point
 *
 *Return: Always 0
 */
int main(void)
{
    char *str = "No special character.\n";
    char _buffer[1024];
    int len = _printf("%S", str, _buffer);

    if (len != 42 || strcmp(_buffer, str) != 0)
    {
        printf("Expected output: %s\n", str);
        printf("Actual output: %s\n", _buffer);
        printf("Test case failed.\n");
    }
    else
    {
        printf("Test case passed.\n");
    }

    return (0);
}
