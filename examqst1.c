#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, stck[50], maxsize, top = (-1), p, i;
    printf("Enter the maxsize: \n");
    scanf("%d", &maxsize);
    printf("Implement\n1.Push Operation\n2.Pop Operation\nand then\n3.Display the stack\n4.Exit\n");
    while (1)
    {
        printf("Enter your choice: \n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if (top == (maxsize - 1))
            {
                printf("Stack Overflow.\n");
            }
            else
            {
                printf("Enter the element for push:");
                scanf("%d", &p);
                top += 1;
                stck[top] = p;
            }
            break;
        case 2:
            if (top == (-1))
            {
                printf("Stack Underflow.\n");
            }
            else
            {
                printf("Deleted element: %d\n", stck[top]);
                top -= 1;
            }
            break;
        case 3:
            if (top == (-1))
            {
                printf("stack is empty.\n");
            }
            else
            {
                for (i = top; i >= 0; i--)
                {
                    printf("%d ", stck[i]);
                }
                printf("\n");
            }
            break;
        case 4:
            exit(1);
        default:
            printf("Choice is not valid.\n");
        }
    }
    return 0;
}