#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 *main - Entry point
 *
 *Return: Always 0
 */
int main(void)
{
    int res;

    printf("Testing case: _printf(\"%%d\", INT_MIN);\n");
    res = _printf("%d", INT_MIN);
    printf("Expected: -2147483648\n");
    printf("Got: %d\n\n", res);

    printf("Testing case: _printf(\"%%i\", -1024);\n");
    res = _printf("%i", -1024);
    printf("Expected: -1024\n");
    printf("Got: %d\n\n", res);

    printf("Testing case: _printf(\"%%i\", INT_MIN);\n");
    res = _printf("%i", INT_MIN);
    printf("Expected: -2147483648\n");
    printf("Got: %d\n\n", res);

    printf("Testing case: _printf(\"%%i + %%i = %%i\\n\", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));\n");
    res = _printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
    printf("Expected: -2147483648 + 2147483647 = -1\n");
    printf("Got: %d\n\n", res);

    return (0);
}
