#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head;
struct Node *new_node;
void insertatBeginning()
{
    printf("Enter the value to insert: \n");
    new_node = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d", &new_node->data);
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
}
void insertatEnd()
{
    printf("Enter the value to insert: \n");
    new_node = (struct Node *)malloc(1 * sizeof(struct Node));
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    new_node->prev = NULL;
    struct Node *temp = head;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}
void createList()
{
    char ch = 'y';
    while (ch == 'y' || ch == 'Y')
    {
        insertatEnd();
        printf("Want to create another node? \n");
        scanf(" %c", &ch);
    }
}
int count()
{
    struct Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
void insertatPos()
{
    int pos, cnt;
    int i = 1;
    struct Node *temp = head;
    new_node = (struct Node *)malloc(1 * sizeof(struct Node));
    printf("Enter the position after which you want to insert: \n");
    scanf("%d", &pos);
    cnt = count();
    if (pos == 1)
    {
        insertatBeginning();
    }
    else if (pos == cnt + 1)
    {
        insertatEnd();
    }
    else if (pos > cnt + 1)
    {
        printf("Position Out of Range \n");
    }
    else
    {
        while (temp != NULL)
        {
            if (i == (pos - 1))
            {
                printf("Enter the value to insert: \n");
                scanf("%d", &new_node->data);
                new_node->prev = temp;
                new_node->next = temp->next;
                temp->next = new_node;
                temp->next->prev = new_node;
                break;
            }
            i++;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            insertatEnd();
        }
    }
}
void insertafterValue()
{
    int v;
    printf("Enter the value to insert: \n");
    new_node = (struct Node *)malloc(1 * sizeof(struct Node));
    scanf("%d", &new_node->data);
    printf("Enter the value after which you want to insert: \n");
    scanf("%d", &v);
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == v)
        {
            new_node->prev = temp;
            new_node->next = temp->next;
            temp->next = new_node;
            temp->next->prev = new_node;
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Node is not found\n");
    }
}
void reverseList()
{
    struct Node *temp = head;
    struct Node *p;
    while (temp != NULL)
    {
        p = temp;
        temp = temp->next;
    }
    while (p != NULL)
    {
        printf("%d-->", p->data);
        p = p->prev;
    }
    printf("NULL");
    printf("\n");
}
void deleteatBeginning()
{
    struct Node *temp = head;
    head->next->prev = NULL;
    head = head->next;
    free(temp);
}
/*
void deleteatEnd()
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
}
void deleteatPos()
{
    int pos, cnt, i = 1;
    struct Node *p = head;
    struct Node *q = head->next;
    printf("Enter the position where you want to delete: \n");
    scanf("%d", &pos);
    cnt = count();
    if (pos > cnt)
    {
        printf("Position not found \n");
    }
    else
    {
        while (i != (pos - 1))
        {
            p = p->next;
            q = q->next;
            i++;
        }
        p->next = q->next;
        free(q);
    }
}
void deleteafterValue()
{
    int val;
    printf("Enter the value after which you want to delete: \n");
    scanf("%d", &val);
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            temp->next = temp->next->next;
            // temp->next->prev = temp;
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Node is not found. \n");
    }
}*/
void display()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}
int main()
{
    int ch;
    printf("Press\n1.Creation\n2.Insert at beginning\n3.Insert at end\n4.Insert at certain position\n5.Insert after given value\n6.Reverse the list\n7.Delete from beginning\n8.Delete at end\n9.Delete at certain position\n10.Delete after given value \n11.Display the Linked list \n12.Exit \n");
    while (1)
    {
        printf("Enter your choice(between 1 to 12): \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            createList();
            break;
        case 2:
            insertatBeginning();
            break;
        case 3:
            insertatEnd();
            break;
        case 4:
            insertatPos();
            break;
        case 5:
            insertafterValue();
            break;
        case 6:
            reverseList();
            break;
        case 7:
            deleteatBeginning();
            break;
        case 8:
            deleteatEnd();
            break;
        case 9:
            deleteatPos();
            break;
        case 10:
            deleteafterValue();
            break;
        case 11:
            display();
            break;
        case 12:
            exit(1);
        default:
            printf("Invalid Choice \n");
        }
    }
    return 0;
}