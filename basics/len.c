#include <stdio.h>

int str_len(char *c)
{
    int i;

    for (i = 0; *c != '\0'; c++)
    {
        i++;
    }
    return (i);
}

int main(void)
{
    str_len("Ajibade");
    str_len("Taofeek Ajibade");

    return (0);
}
