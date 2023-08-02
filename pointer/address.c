#include <stdio.h>
/*
int main(void)
{
	int myvar; 
	char myvar2[20];

	printf("The address of myvar is %p\n", &myvar);
	printf("The address of myvar2 is %p\n", &myvar2);
}
*/

/**
 * NULL Pointers - used when there is no exact address to be assigned.
 * Return value is zero
 */

int main(void)
{
	int *ptr = NULL;

	printf("The value of ptr is : %x\n", ptr); /* output = 0 */
	printf("The address of ptr is : %p\n", &ptr); /* prints the address of the variable */

	return (0);
}
