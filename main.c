#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void main()
{
    int c = 0;

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));

    struct Node *last = head;

    printf("Enter value for head : ");
    scanf(" %d", &head->data);

    while (1)
    {
        printf("To make new node enter 1 ? ");
        scanf(" %d", &c);
        if (c != 1)
        {
            last->next = NULL;
            break;
        }

        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter value for current node : ");
        scanf(" %d", &temp->data);

        last->next = temp;
        last = temp;
    }

    struct Node *curr = head;
    while (1)
    {
        printf("%d", curr->data);
        if (curr->next == NULL)
            break;
        curr = curr->next;
    }
}
