#include <stdio.h>
#include <stdlib.h>
/**
 * main - allocates memory to a variable
 * Return: NULL if failed or 0 on success
 */
int main(void)
{
	int size = 15;
	int i;
	int *dynamicArray;

	dynamicArray = malloc(size * sizeof(int));
	if (dynamicArray == NULL)
		printf("Memory allocation failed.\n");
		return (1);
	for (i = 0; i < size; i++)
		dynamicArray[i] = i * 5;
	for (i = 0; i < size; i++)
		printf("The elements are: %d : %d\n", i, dynamicArray[i]);
	free(dynamicArray);

	return (0);
}
