#include <stdio.h>

int main(void)
{
	int age;

	printf("Enter your real age...\n");
	scanf("%d", &age);
	if (age < 50) {
		printf("Wow! What a young man!\n");
	}
	else if (age < 70 && age > 50) {
		printf("You are a pretty old man. Fantastic!\n");
	}
	else if (age >= 70 && age < 100) {
		printf("You are now a grandpa. Enjoy your time.\n");
	}
	else
		printf("You are a centenarian. Wishing you a peaceful and joyous ending.\n");
	return (0);
}

