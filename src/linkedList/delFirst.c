#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int count = 0;
struct Node *temp = NULL;
struct Node *head = NULL;
struct Node *last = NULL;
struct Node *curr = NULL;

void insert()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf(" %d", &temp->data);

    if (!head)
    {
        head = temp;
        last = head;
        head->next = NULL;
        return;
    }

    last->next = temp;
    temp->next = NULL;
    last = temp;
}

void display()
{
    count = 0;
    curr = head;

    while (1)
    {
        if (!curr)
            return (void)printf("Linked list has %d nodes present.\n", count);

        printf("{ data : %d next : %p }\n", curr->data, curr->next);
        curr = curr->next;
        count++;
    }
}

void delFirst()
{

    if (!head)
        return (void)printf("Linked list is empty.\n");

    temp = NULL;
    if (head->next)
        temp = head->next;

    free(head);
    head = temp;
}

void main()
{
    int choice;

    while (1)
    {
        printf("Enter your choice | 1. Insert | 2. Display | 3. Delete First Node | : ");
        scanf(" %d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            display();
            break;

        case 3:
            delFirst();
            break;

        default:
            exit(0);
            break;
        }
    }
}