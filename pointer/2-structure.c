#include <stdio.h>
#include <stdlib.h>

struct UserData
{
	char *name;
	char *address;
	char *gender;
	int age;
	int Id;
};

struct UserData *new_users(char *name, char *address, char *gender, int age, int Id)
{
	struct UserData *user;

	user = malloc(sizeof(struct UserData));
	if (user == NULL)
		return (NULL);
	(*user).name = name;
	(*user).address = address;
	(*user).gender = gender;
	(*user).age = age;
	(*user).Id = Id;
}

int main(void)
{
	struct UserData *user;

	user = new_users("Julien Barbier", "Lagos, Nigeria", "Male", 54, 1001);
	if (user == NULL)
		return (1);
	printf("The first user created is %s\n", user->name);
	printf("Location is %s\n", user->address);
	printf("A %s\n", user->gender);
	printf("He is %d years old\n", user->age);
	printf("His Id is created as %d\n", user->Id);

	return (0);
}
