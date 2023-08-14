#include <stdio.h>
/**
 * addition - adds two values
 * @a: value 1
 * @b: value 2
 * Return: result
 */
int addition(int a, int b)
{
	return (a + b);
}
/**
 * subtraction - subtract 2nd value from first value
 * @a: value 1
 * @b: value 2
 * Return: result
 */
int subtraction(int a, int b)
{
	return (a - b);
}
/**
 * main - prints values on function call
 * Return: Always 0 (success)
 */
int main(void)
{
	int (*functptr)(int, int); /* declares pointer to a function */

	functptr = addition; /* calls pointer to add values */
	printf("Addition of two values: %d\n", functptr(72, 27));

	functptr = subtraction; /* calls pointer to subtract values */
	printf("Subtraction of two values: %d\n", functptr(1034, 843));

	return (0);
}
