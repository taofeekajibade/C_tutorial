#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int a = 524;
	int b = 276;
	int subtraction = a - b;
	pid_t ppid;

	ppid = getppid();

	printf("The sum is equal to %d\n", subtraction);
	printf("The ppid is equal to %u\n", ppid);

	return (0);
}
