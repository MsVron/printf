#include "main.h"

int main(void)
{
	int num = 123;
	char *str = "Hello, world!";

	_printf("%s\n", str);
	_printf("%d\n", num);
	_printf("%b\n", num);
	_printf("%o\n", num);
	_printf("%x\n", num);
	_printf("%X\n", num);
	_printf("%%\n");

	return (0);
}
