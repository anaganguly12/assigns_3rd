#include <stdio.h>
#include <stdlib.h>
#define Maxsize 3
int front = -1, rear = -1;
int cq[Maxsize];

void enqueue(int x)
{
    if ((front == 0 && rear == Maxsize - 1) || (front == rear + 1))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (rear == Maxsize - 1)
        {
            rear = 0;
        }
        else
        {
            rear = rear + 1;
        }
        cq[rear] = x;
    }
}

int dequeue()
{
    int y;
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        y = cq[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == Maxsize - 1)
        {
            front = 0;
        }
        else
        {
            front = front + 1;
        }
        return y;
    }
}

void display()
{
    int i, j;
    if (front != -1 && rear != -1)
    {
        if (front <= rear)
        {
            for (i = front; i <= rear; i++)
            {
                printf("%d ", cq[i]);
            }
        }
        else
        {
            for (j = front; j < Maxsize; j++)
            {
                printf("%d ", cq[j]);
            }

            for (j = 0; j <= rear; j++)
            {
                printf("%d ", cq[j]);
            }
        }
    }
    else
    {
        printf("Queue is Empty\n");
    }
}
int main()
{
    int choice, ele, del;
    printf("Implement CIRCULAR QUEUE's Following Operations\n");
    printf("1.Insertion(Enqueue)\n2.Deletion(Dequeue)\n3.Display the Queue\n4.Exit\n");
    while (1)
    {
        printf("Enter your Choice(1/2/3/4): \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a element to insert: \n");
            scanf("%d", &ele);
            enqueue(ele);
            break;
        case 2:
            del = dequeue();
            if (del != -1)
            {
                printf("Deleted Element is: %d\n", del);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Choice is not valid\n");
        }
    }

    return 0;
}