#include <stdio.h>
#include <stdlib.h>

struct myNode
{
	char data;
	struct myNode *next;
};

char print_elements(struct myNode *head)
{
	int count = 0;

	while (head != NULL)
	{
		printf("The nodes are: %c %c\n", count+1, head->data);
		head = head->next;
		count++;
	}
	return (count);
}

int main(void)
{
	struct myNode *node1 = malloc(sizeof(struct myNode));
	struct myNode *node2 = malloc(sizeof(struct myNode));
	struct myNode *node3 = malloc(sizeof(struct myNode));
	struct myNode *node4 = malloc(sizeof(struct myNode));
	node1->data = 'A';
	node2->data = 'B';
	node3->data = 'C';
	node4->data = 'D';

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	int elements = print_elements(node1);
	printf("The total number of nodes is: %d\n", elements);
	free(node1);
	free(node2);
	free(node3);
	free(node4);

	return (0);
}
