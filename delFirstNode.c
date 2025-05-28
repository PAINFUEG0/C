#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *makeNode()
{
    return (struct Node *)malloc(sizeof(struct Node));
}

struct Node *head;
struct Node *lastAssigned;

void insert()
{

    struct Node *temp = makeNode();

    printf("Enter value for current node : ");
    scanf(" %d", &temp->data);

    if (!head->data)
    {
        head->data = !head->data;

        head = temp;
        lastAssigned = head;
        return;
    }

    lastAssigned->next = temp;
    lastAssigned = temp;
}

void display()
{
    if (!head->data)
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

void deleteFirst()
{
    if (!head->data)
    {
        printf("No nodes present !!!\n");
        return;
    }

    struct Node *temp = head->next;
    free(head);
    head = temp;
}

void main()
{
    head = makeNode();
    int choice;

    while (1)
    {
        printf("Enter an option :| 1 (Insert) | 2 (Display) | 3 (Del_Head): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            display();
            break;

        case 3:
            deleteFirst();
            break;

        default:
            exit(1);
            break;
        }
    }
}
