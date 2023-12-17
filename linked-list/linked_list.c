#include <stdio.h>
#include <stdlib.h>

/* define the structure of the linked list */
struct Node {
    int data;
    struct Node* next; /* a pointer to the next node */

};

/* allocate memory to the data */

struct Node* myNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return (node);
}

/* Initialize and insert elements */

struct Node* head = NULL;

// void insertNodebegin(int data)
// {
//     struct Node* newElement = myNode(data); /* data */
//     newElement->next = head;
//     head = newElement;
// }

void insertEnd(int data)
{
    struct Node* endElement = myNode(data);
    head->next = endElement;
    endElement->next = NULL;
    
}

void displayList() {
    struct Node* current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(void)
{
    // insertNodebegin(204);
    // insertNodebegin(320);
    // insertNodebegin(465);
    insertEnd(25);
    insertEnd(32);
    insertEnd(14);

    printf("Students IDs in the class\n");
    displayList();
}