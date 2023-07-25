#include <stdio.h>

void kilode(){
	printf("Kilodee gan-an naa!\n");
}
void esora()
{
	printf("E kilo fun Gomina yin o\n");
}

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		kilode();
		for (int j = 0; j < 5; j++)
		{
			esora();
		}
	}
	return (0);

}
