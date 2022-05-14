#include <stdio.h>
int binarySearch(int arr[], int n, int key)
{
    int lb = 0, ub = (n - 1), mid;
    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            lb = mid + 1;
        }
        else
        {
            ub = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n, arr[100], key, index, i;
    printf("Enter the value of n: \n");
    scanf("%d", &n);

    printf("Enter the elements of the array: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of key: \n");
    scanf("%d", &key);

    index = binarySearch(arr, n, key);
    if (index == -1)
    {
        printf("%d is not found at any index.", key);
    }
    else
    {
        printf("%d is present at index %d.", key, (index + 1));
    }

    return 0;
}
