#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * str_len - calculates the lenght of a string
 * @arr: argument 1
 */

int str_len(char *arr)
{
	int arr_len = 0;

	while(*arr != '\0')
	{
		arr_len++;
		arr++;
	}
	return (arr_len);
}

int main(void)
{
	int lenght = 0;

	char array[] = "I am attending an online C class on function";
	lenght = str_len(array);
	/*printf("The lenght of the array is %d", lenght);*/
	write(1, array, lenght);
	/*putchar(lenght/10 + '\0');*/
	/*putchar(lenght%10 + '\0');*/
	return (0);
}
