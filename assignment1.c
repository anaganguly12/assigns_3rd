#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n = 0;
    int arr[100], i, c, p = 0;
    int pmax = 0, pmin = 0;
    int max, min;
    int num;
    int position = 0;
    int dlt;
    printf("Enter the no of element of array-\n");
    scanf("%d", &n);
    printf("Insertion of element in the array-\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    while (1)
    {
        printf("1:To find max min\n");
        printf("2:To insert a element in a array\n");
        printf("3:To delete a element in a array\n");
        printf("4:To display the array\n");
        printf("5:To exit the program\n");
        printf("Enter your choice what you want to do-\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            max = arr[0];
            min = arr[0];
            for (i = 0; i < n; i++)
            {
                if (arr[i] > max)
                {
                    max = arr[i];
                    pmax = i;
                }
                if (arr[i] < min)
                {
                    min = arr[i];
                    pmin = i;
                }
            }
            printf("The maximum element is %d and its position is %d\n", max, pmax + 1);
            printf("The minimum element is %d and its position is %d\n", min, pmin + 1);
            break;
        case 2:
            printf("Enter the element to insert-\n");
            scanf("%d", &num);
            printf("Enter the position where you want to insert the element-\n");
            scanf("%d", &p);
            for (i = n; i >= p; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[p - 1] = num;
            n++;
            break;
        case 3:
            printf("Enter the position to delete-\n");
            scanf("%d", &dlt);
            for (i = dlt - 1; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            n--;
            break;
        case 4:
            printf("Here is the array\n");
            for (i = 0; i < n; i++)
                printf("%d\n", arr[i]);
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong Choice");
        }
    }
    return 0;
}