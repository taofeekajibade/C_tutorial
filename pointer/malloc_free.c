#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
int main(void)
{
	int *array;

	array = malloc(3000 * sizeof(int));
	for (int i = 0; i < 1000; i++)
		printf("%d", array[i]);
	free(array);

	printf("\n");

return (0);
}
*/

int main(void)
{
	clock_t *tic, *toc;
	int *array;

	tic = clock();
	array = malloc(100000 * sizeof(int) );
	toc = clock();
	printf("malloc: %f\n", (double) (toc - tic) / CLOCKS_PER_SEC );
	free(array);


	tic = clock();
	array = calloc(100000, sizeof(int) );
	toc = clock();
	printf("calloc: %f\n", (double) (toc - tic) / CLOCKS_PER_SEC );
	free(array);


return (0);
}
