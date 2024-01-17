#include <stdio.h>
/**
 * main - function searches names of food from an array of food items.
*/

int main(void)
{
    int i;
    /* array of food items */
    char *food [] = {"rice", "gaari", "beans", "banana", "yam", "maize", "semo"};

    for (i = 0; i < 7; i++)
    {
        if (food[i] == "banana")
        {
            printf("food is found in index %d\n", i);
            return (0);
        }
    }
    printf("food item not found.\n");

    return (0);
}