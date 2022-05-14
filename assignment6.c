#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAXSIZE 10
int stck[MAXSIZE], top = (-1);
void push(int x)
{
    if (top == (MAXSIZE - 1))
    {
        printf("\n Stack Overflow");
    }
    else
    {
        top++;
        stck[top] = x;
    }
}
int pop()
{
    int y = -1;
    if (top == (-1))
    {
        printf("Stack Underflow");
    }
    else
    {
        y = stck[top];
        top--;
    }
    return y;
}
int main()
{
    char p[100];
    int i = 0, val, x, y, z;
    printf("\n Enter the postfix expression: \n");
    gets(p);

    while (p[i] != '\0')
    {
        if (isalpha(p[i]))
        {
            printf("\n Enter the value for operand: %c\n", p[i]);
            scanf("%d", &val);
            push(val);
        }
        else
        {
            x = pop();
            y = pop();
            switch (p[i])
            {
            case '+':
                z = y + x;
                break;
            case '-':
                z = y - x;
                break;
            case '*':
                z = y * x;
                break;
            case '/':
                z = y / x;
                break;
            case '^':
                z = pow(y, x);
                break;
            case '%':
                z = y % x;
                break;
            }
            push(z);
        }
        i++;
    }
    printf("The evaluted result of postfix expression: %d\n", stck[top]);
    return 0;
}