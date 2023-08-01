#include <stdio.h>
int main(){

int fahr;
#define STEP 20 /*The step from one value to another*/
#define LOWER 0 /*The lower value of the celcius*/
#define UPPER 500 /*The upper value of the celcius*/

for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
	printf("%d\t%.1f\n", fahr, (5.0/9.0)*(fahr-32));
	return 0;
}
