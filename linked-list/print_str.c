#include <stdio.h>
#include <stdlib.h>

struct myNode
{
	char *data;
	struct myNode *next;
};

char print_elements(struct myNode *head)
{
	int count = 0;

	while (head != NULL)
	{
		printf("The nodes are: %d %s\n", count+1, head->data);
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
	node1->data = strdup("I love my country.");
	node2->data = strdup("I will not lie about this.");
	node3->data = strdup("I will live and die in it.");
	node4->data = strdup("God bless my country.");

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	int elements = print_elements(node1);
	printf("The total number of nodes is: %d\n", elements);
	free(node1->data);
	free(node2->data);
	free(node3->data);
	free(node4->data);
	free(node1);
	free(node2);
	free(node3);
	free(node4);

	return (0);
}
