#include <stdio.h>
#include <stdlib.h>

struct myNode
{
	int data;
	struct myNode *next;
};

int print_node_num(struct myNode *head)
{
	int count = 0;

	while (head != NULL)
	{
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
	node1->data = 35;
	node1->data = 79;
	node1->data = 84;
	node1->data = 75;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	int node_number = print_node_num(node1);
	printf("The total number of nodes is: %d\n", node_number);
	free(node1);
	free(node2);
	free(node3);
	free(node4);

	return (0);
}
