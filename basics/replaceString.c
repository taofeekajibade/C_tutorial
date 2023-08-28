#include <stdio.h>

int main(void) {
    int currentChar, previousChar;

    previousChar = EOF; // Set previousChar to an initial value

    while ((currentChar = getchar()) != EOF) {
        if (currentChar != ' ' || previousChar != ' ')
            putchar(currentChar);
        
        previousChar = currentChar;
    }

    return 0;
}

/*Write a programme to copy its input to its output, replacing each string of one or more blanks by a single blank.*/
