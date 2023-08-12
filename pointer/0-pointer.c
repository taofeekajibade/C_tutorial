#include <stdio.h>

int main(void)
{
    int c;
    int *p;

    p = &c;
    printf("Enter a number here...");
    scanf("%d", &c);
    printf("The direct value you entered is: %d\n", c);
    printf("It can also be written as %d\n", *p); /* dereferencing */
    printf("The direct memory Address is: %p\n", &c); /* using address-of specifier */
    printf("We may also get it via p this way: %p\n", p); /* using pointer to get address */
    
    printf("Hello World\n");
  return 0;
}
