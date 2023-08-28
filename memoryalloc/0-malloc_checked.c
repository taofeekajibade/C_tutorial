#include <stdio.h>

void print_failed(void)
{
    char *str = "Adewale";      /* declares a pointer to string str.*/

    str[1] = 'j';       /* modifies the value of the 2nd character in the string*/
    printf("%s\n", str); /* segmentation fault: *str is only a pointer to 
                            the string and is thus only readable. */
}

void print_success(void)
{
    char str[] = "Adewale"; /* declares an array named str.*/

    str[1] = 'j'; /* modifies the value of the 2nd character in the array*/
    printf("%s\n", str);
}

int main(void)
{
    print_success();
    return (0); /*prints Ajewale to the output*/
}