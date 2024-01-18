#include <stdio.h>
#include <string.h>
/**
 * main - function searches names of food from an array of food items.
*/

int main(void)
{
    int i;
    char food_item[100];
    /* array of food items */
    char *food[] = {"rice", "gaari", "beans", "banana", "yam", "maize", "semo"};

    printf("Enter a food item: ");
    scanf("%s", food_item);

    for (i = 0; i < 7; i++)
    {
        if (strcmp(food[i], food_item) == 0) /*This is a better equivalent of "if (food[i] == food_item)'*/
        {
            printf("food is found in index %d\n", i);
            return (0);
        }
    }
    printf("food item not found.\n");


    return (0);
}