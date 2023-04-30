#include <stdio.h>
#include <limits.h>
#include "main.h"

/**
 *main - Entry point
 *
 *Return: Always 0
 */
int main(void)
{
	int ret, expected;

	/*Test case 1: printing INT_MIN with %d */
	ret = _printf("%d", INT_MIN);
	expected = printf("%d", INT_MIN);
	printf("Got: %d\nExpected: %d\n", ret, expected);

	/*Test case 2: printing INT_MIN and INT_MAX with %d */
	ret = _printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	expected = printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("Got: %d\nExpected: %d\n", ret, expected);

	/*Test case 3: printing INT_MIN with %i */
	ret = _printf("%i", INT_MIN);
	expected = printf("%i", INT_MIN);
	printf("Got: %d\nExpected: %d\n", ret, expected);

	/*Test case 4: printing INT_MIN and INT_MAX with %i */
	ret = _printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	expected = printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("Got: %d\nExpected: %d\n", ret, expected);

	return (0);
}
