#include <stdio.h>

struct employee {
    char name[30];
    int level;
    int entry;
    float salary;
};

int main(void)
{
    struct employee abe = {"Taofeek Ajibade", 14, 2005, 720000};

    printf("This is a sample structure with ClearGoal.\n");

    printf("The name of the new employee is %s\n. His level is %d\nemployed in %d\nand on a salary of %lf\n", abe.name, abe.level, abe.entry, abe.salary);

    return (0);
}
