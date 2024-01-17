/*
#include <stdio.h>


int main(void)
{
    float result = 2553.71 / 4.2;
    int new_result = 608 * 4.2;

    printf("The result is %f\n", result);
    printf("The 2nd result is %d\n", new_result);

    return (0);
}
*/
/*
int main(void)
{
    int width = 3;
    int height = 5;
    int length = 6.8;
    int breadth = 2.3;

    int area_of_rectangle = (width*3) * (22/7);
    int perim_of_rectangle = width*height;

    /* A program to print username, social security number and date of birth
    char *myName = "Taofeek Ajibade";
    int ss_num = 12309876;
    char *d_o_b = "01-02-1995";

    printf("My name is %s. My social number is %d, and my date of birth is %s\n", myName, ss_num, d_o_b);

    printf("The area of rectangle is %d\n", area_of_rectangle);
    printf("The preim of rectangle is %d\n", perim_of_rectangle);

    return (0); 
}
*/

#include <stdio.h>

int main(void)
{
    int height = 9;
    int width = 6;

    int i, j;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || i == height / 2 || j == 0)
                printf("*#");
            else
                printf(".");
        }
        printf("\n");
    }

    return 0;
}