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
	int len;
	long int l;

	len = _printf("%d", 1024);
	printf("Length: %d\n", len); /*Expected length: 4 */
	len = _printf("%d", -1024);
	printf("Length: %d\n", len); /*Expected length: 5 */
	len = _printf("%d", 0);
	printf("Length: %d\n", len); /*Expected length: 1 */
	len = _printf("%d", INT_MAX);
	printf("Length: %d\n", len); /*Expected length: 10 */
	len = _printf("%d", INT_MIN);
	printf("Length: %d\n", len); /*Expected length: 11 */

	l = INT_MAX;
	l += 1024;
	len = _printf("%d", l);
	printf("Length: %d\n", len); /*Expected length: 10 */

	l = INT_MIN;
	l -= 1024;
	len = _printf("%d", l);
	printf("Length: %d\n", len); /*Expected length: 11 */

	len = _printf("There is %d bytes in %d KB\n", 1024, 1);
	printf("Length: %d\n", len); /*Expected length: 29 */

	len = _printf("%d - %d = %d\n", 1024, 2048, -1024);
	printf("Length: %d\n", len); /*Expected length: 20 */

	len = _printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("Length: %d\n", len); /*Expected length: 22 */

	len = _printf("%i", 1024);
	printf("Length: %d\n", len); /*Expected length: 4 */
	len = _printf("%i", -1024);
	printf("Length: %d\n", len); /*Expected length: 5 */
	len = _printf("%i", 0);
	printf("Length: %d\n", len); /*Expected length: 1 */
	len = _printf("%i", INT_MAX);
	printf("Length: %d\n", len); /*Expected length: 10 */
	len = _printf("%i", INT_MIN);
	printf("Length: %d\n", len); /*Expected length: 11 */

	return (0);
}
