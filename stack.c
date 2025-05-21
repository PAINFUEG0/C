#include <stdio.h>
#include <stdlib.h>

#define maxCapacityOfStack 5

int top = -1;
int stack[maxCapacityOfStack];

int push(int value)
{
    if (top == maxCapacityOfStack - 1)
    {
        printf("Can't push as pushing will cause the Stack to Overflow\n");
        return 0;
    }

    stack[++top] = value;
    printf("Pushed %d to stack\n", value);
    return top;
}

int pop()
{
    if (top == -1)
    {
        printf("Can't pop as popping will cause the Stack to Underflow\n");
        return 0;
    }
    printf("Popped %d from stack\n", stack[top]);
    --top;
    return top;
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty !\n");
        return;
    }

    printf("[ ");
    for (int i = 0; i <= top; i++)
        printf("%d, ", stack[i]);
    printf("]\n");
}

void main()
{
    int choice, element;

    while (1)
    {
        printf("Enter an option :| 1 (Push) | 2 (Pop) | 3 (Display) | : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number to push\n");
            scanf("%d", &element);
            push(element);
            break;

        case 2:
            pop();
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
