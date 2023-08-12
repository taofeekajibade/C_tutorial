#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, n, *ptr;

	printf("Enter a value here: ");
	scanf("%d", &n);
	ptr = (int *)malloc(n*sizeof(int));

	if (ptr == NULL)
	{
		printf("Memory not available.");
		exit(1);
	}
	for (i = 0; i < n; i ++)
	{
		printf("Enter another positive value: ");
	scanf("%d", ptr + i);
	}
	for (i = 0; i < n; i++)
		printf("%d ", *(ptr + i));
	return (0);
}
