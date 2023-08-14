#include <stdio.h>
#include <stdarg.h>

int addition(int count, ...)
{
	int result = 0;
	int i;

	va_list args;
	va_start(args, count);

	for (i = 0; i < count; i++)
	{
		int list = va_arg(args, int);
		result += list;
	}
	va_end(args);

	return (result);
}

int main(void)
{
	int result_1;
	int result_2;

	result_1 = addition(5,7, 56, 3, 25, 74);
	result_2 = addition(7, 62, 78, 52, 83, 94,26, 89);
	printf("The first sum: %d\n", result_1);
	printf("The second sum: %d\n", result_2);

	return (0);
}
