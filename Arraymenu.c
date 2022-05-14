#include <stdio.h>
int arr[50];
int main()
{
    int n, i, ch, maxele, minele, pmax = 0, pmin = 0, ele, pos;
    printf("Enter the size of the array: \n");
    scanf("%d", &n);
    printf("Enter the elements of the array: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    while (1)
    {
        printf("Implement the following operation: \n");
        printf("1.Find the maximum and minimum element of the array. \n");
        printf("2.Insert element in the array \n");
        printf("3.Delete element from the array \n");
        printf("4.Display the array\n");
        printf("5.Exit \n");

        printf("Enter your choice: \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            maxele = arr[0], minele = arr[0];
            for (i = 0; i < n; i++)
            {
                if (arr[i] > maxele)
                {
                    maxele = arr[i];
                    pmax = i;
                }
                if (arr[i] < minele)
                {
                    minele = arr[i];
                    pmin = i;
                }
            }
            printf("The maximum element of the array is : %d, present at %d\n", maxele, pmax + 1);
            printf("The minimum element of the array is : %d, present at %d\n", minele, pmin + 1);
            break;
        case 2:
            printf("Enter the element you want to insert: \n");
            scanf("%d", &ele);
            printf("Enter the position where you want to insert: \n");
            scanf("%d", &pos);

            for (i = n - 1; i >= pos; i--)
            {
                arr[i + 1] = arr[i];
            }
            arr[pos - 1] = ele;
            n++;
            break;
        case 3:

            break;
        case 4:
            printf("Elements of this array: \n");
            for (i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        default:
            break;
        }
    }

    return 0;
}