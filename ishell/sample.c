#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int a = 52;
	int b = 26;
	int sum = a + b;
	pid_t pid;

	pid = getpid();

	printf("The sum is equal to %d\n", sum);
	printf("The pid is equal to %u\n", pid);

	return (0);
}
