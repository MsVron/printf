#include "main.h"

int main(void)
{
	int num = 123;
	char *str = "Hello, world!";

	_printf("%s\n", str);
	_printf("%d\n", num);
	_printf("%b\n", num);	// should print 1111011
	_printf("%o\n", num);	// should print 173
	_printf("%x\n", num);	// should print 7b
	_printf("%X\n", num);	// should print 7B
	_printf("%%\n");	// should print %

	return (0);
}
