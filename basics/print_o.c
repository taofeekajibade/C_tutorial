#include <stdio.h>
/**
 * A simple program to print letter O to the stdout
 */
int main(void)
{
    int i, j; /* counter to iterate rows and columns */
    int circle = 7;

    for (i = 0; i < circle; i++) /* iterate vertical lenght */
    {
        for (j = 0; j < circle; j++) /* iterate the width */
        {
            if((i == 0 || i == circle-1) && (j > 0 && j < circle-1)) /* conditions to print letter O */
            {
                printf("*");
            }
            else if ((i > 0 && i < circle-1) && (j == 0 || j == circle-1))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
     }
    return (0);
}
