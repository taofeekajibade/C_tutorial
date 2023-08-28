#include <stdarg.h>
#include <stdio.h>

void printnum(int numbers, ...)
{
	va_list list;
	int i;
	
	va_start(list, numbers);
	for (i = 0; i < numbers; i++)
		printf("%d ", va_arg(list, int));
	va_end(list);
	putchar('\n');
}

int main(void)
{
	printnum(5, 9, 3, 2, 8, 6);
	printnum(4, 5, 3, 2, 6);
	printnum(7, 8, 3, 2, 8, 6, 9, 10);
	
	return (0);

	}
