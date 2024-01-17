#include <stdio.h>
/**
 * main - a function that searches for a number from an array of numbers
*/

int main(void)
{
    int i;
    int arr [] = {3, 4, 5, 1, 9, 0, 6}; /* array of numbers*/

    for (i = 0; i < 7; i++) /* loop though the array*/
    {
        if (arr[i] == 4) /* look for specified number */
        {
            printf("I have found it in position %d\n", i); /* print a statement if found*/
            return (0);
        }
    }
     /* or this statement if not found*/
    printf("Number not found!\n");

    return (0);
}