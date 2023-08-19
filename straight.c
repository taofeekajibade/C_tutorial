#include <stdio.h>

void print_line(int n)
{
	int i;

	for (int i = 0; i < n; i++)
	{
		putchar('|');
		putchar('\n');
	}
}

int main(void)
{
	print_line(5);
	
	return (0);
}
