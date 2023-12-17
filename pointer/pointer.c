#include <stdio.h>

int main(void)
{
    int age = 45; /* initialize age with 25 */
    int *ptr = &age; /* assigns the address of age to ptr */

    printf("The address of the age is %p\n", ptr);
    printf("The address of the aged is %p\n", ptr+1);
    printf("The age of the student is %d\n", *ptr);
    printf("The age of the student is %d\n", age);
    printf("++*ptr = %d\n", ++*ptr+1);
    printf("(*ptr)++ = %d\n", (*ptr)++);
    printf("*ptr++ = %d\n", *ptr++);

    return (0);
}

