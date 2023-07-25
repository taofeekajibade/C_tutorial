#include <stdio.h>

int main(void)
{
	for (int i = 1; i <= 20; i++)
	{
		for (int j = 1; j <= 20; j++)
		{
			printf("%d x %d =%d\n",i, j, i*j);
		}
		printf("\n");
	}
	return (0);
}
