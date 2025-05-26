#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;
struct Node *last;
int isHeadAssigned = 0;

void insert()
{

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value for current node : ");
    scanf(" %d", &temp->data);

    if (!isHeadAssigned)
    {
        head = temp;
        last = head;
        isHeadAssigned = !isHeadAssigned;
        return;
    }

    last->next = temp;
    last = temp;
}

void display()
{
    if (!isHeadAssigned)
    {
        printf("No nodes present !!!\n");
        return;
    }

    struct Node *curr = head;

    printf("Linked list (Nodes) : \n[ ");
    while (1)
    {

        printf(curr->next == NULL ? "\n\t{ data: %d, next: NULL }" : "\n\t{ data: %d, next: %p }", curr->data, curr->next);
        if (curr->next == NULL)
            break;
        curr = curr->next;
    }
    printf("\n]\n");
}

void main()
{

    int choice;

    while (1)
    {
        printf("Enter an option :| 1 (Insert) | 2 (Display) | : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            display();
            break;

        default:
            exit(1);
            break;
        }
    }
}
