#include <stdarg.h>
#include <stdio.h>

int add_num(int numbers, ...)
{
	int result = 0;
	va_list list;
	int i;
	
	va_start(list, numbers);
	for (i = 0; i < numbers; i++)
		result += va_arg(list, int);
	return (result);

	va_end(list);
	putchar('\n');
}

int main(void)
{
	int sum1;
	int sum2;

	sum1 = add_num(5, 19, 73, 62, 58, 66);
	sum2 = add_num(4, 15, 43, 22, 46);

	printf("The first total is %d\n ", sum1);
	printf("The second total is %d\n ", sum2);

	return (0);

}
