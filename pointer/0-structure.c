#include <stdio.h>

struct studentData {
	char *stdname;
	char *stdclass;
	int stdage;
	char stdgender;
};

int main(void)
{
	struct studentData student;

	student.stdname = "Taofeek Ajibade";
	student.stdclass = "senior";
	student.stdage = 20;
	student.stdgender = 'M';

	printf("The student's name is %s\n", student.stdname);
	printf("The student's name is %s\n", student.stdclass);
	printf("The student's name is %d\n", student.stdage);
	printf("The student's gender is %c\n", student.stdgender);

	return (0);
}
