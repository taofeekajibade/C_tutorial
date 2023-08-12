#include <stdlib.h>

int main(void)
{
	int *ptr; /* declares a pointer ptr as an integer. */
	char *mychar; /* declares a pointer mychar that points to a character */

	ptr = malloc(sizeof(int)); /* alllocates memory to pointer */
	mychar = malloc( sizeof(*mychar) ); /* same as above but more flexible in changing the data type. */
	return (0); 
}
