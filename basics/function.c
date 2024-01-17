#include <stdio.h>

void say_hello()
{
    printf("Good morning, everyone!");
}

int main(void)
{
    int i;
    int user_count;

    printf("Enter a value here: ");
    scanf("%d", &user_count);

    /* use while loop */
    while(i < user_count)
    {
        say_hello();
        printf("\n");
        i++;
    }

    /* or, use for-loop */

    // for (i = 0; i < user_count; i++)
    // {
    //     say_hello();
    //     printf("\n"); 
    // }

    /* use do-while loop */
    // do{
    //     say_hello();
    //     printf("\n");
    //     i++;

    // }while(i < user_count);

    return (0);
}