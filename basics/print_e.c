#include <stdio.h>
/**
 * A simple program to print letter E to the stdout
 */
int main(void)
{
    int i, j; /* counter to iterate rows and columns */
    int height = 7;
    int breadth = 5;

    for (i = 0; i < height; i++) /* iterate vertical lenght */
    {
        for (j = 0; j < breadth; j++) /* iterate the width */
        {
            if (i == 0 || i == height - 1 || i == height / 2 || j == 0) /* conditions to print letter E */
            {
                printf("##");
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
