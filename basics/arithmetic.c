#include "main.h"
#include <stdio.h>

int main(void)
{
    int addition;
    int subt;
    int multiply;

    addition = add(89, 26);
    subt = sub(11024, 8076);
    multiply = mult(154, 211);
    printf("The result of the adition of (1889 and 426) is : %d\n", addition);
    printf("The result of the subtraction of (11024 and 8076) is : %d\n", subt);
    printf("The result of the multiplication of (154 and 221) is : %d\n", multiply);
    return (0);
}