#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, i, *ptr;
	
	printf("Enter number of values...\n");
	scanf("%d", &n);
	ptr = (int *)malloc(n*sizeof(int));
	printf("Enter value...");
	for (i = 0; i < n; i++)
	{
		scanf("%d", (ptr + i));
	}
	printf("The values you have entered are: ");
	{
	for (i = 0; i < n; i++)
		printf("%d\n", *(ptr + i));
	}
	free (ptr);
}
