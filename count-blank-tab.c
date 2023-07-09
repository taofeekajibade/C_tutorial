#include <stdio.h>

int main(void) {
    int c;
    int blankCount = 0;
    int tabCount = 0;
    int newlineCount = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            blankCount++;
        else if (c == '\t')
            tabCount++;
        else if (c == '\n')
            newlineCount++;
    }

    printf("Blanks: %d\n", blankCount);
    printf("Tabs: %d\n", tabCount);
    printf("Newlines: %d\n", newlineCount);

    return 0;
}
