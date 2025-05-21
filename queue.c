#include <stdio.h>
#include <stdlib.h>
#define maxCapacity 2

int queue[maxCapacity];

int r = -1;

void push(int value)
{

    if (r + 1 > maxCapacity - 1)
    {
        printf("Overflow\n");
        return;
    }

    r++;
    queue[r] = value;
    printf("Pushed %d\n", queue[r]);
}

void shift()
{
    if (r - 1 < -1)
    {
        printf("undeflow\n");
        return;
    }

    int shiftedValue = queue[0];

    for (int i = 0; i < r; i++)
        queue[i] = queue[i + 1];

    r--;
    printf("Shifted %d\n", shiftedValue);
}

void display()
{
    if (r < 0)
    {
        printf("Empty\n");
        return;
    }

    printf("[ ");
    for (int i = 0; i <= r; i++)
        printf("%d,", queue[i]);
    printf(" ]\n");
}

void main()
{
    int choice, element;

    while (1)
    {
        printf("Enter an option :| 1 (Push) | 2 (Shift) | 3 (Display) | : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number to push : ");
            scanf("%d", &element);
            push(element);
            break;

        case 2:
            shift();
            break;

        case 3:
            display();
            break;

        default:
            exit(1);
            break;
        }
    }
}
