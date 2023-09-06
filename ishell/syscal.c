#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;

	printf("First trial of fork\n");
	pid = fork();

	if (pid == -1)
	{
		perror("unsuccessful");
		return (-1);
	}
	printf("Successful\n");

	return (0);
}
