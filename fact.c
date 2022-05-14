#include <stdio.h>
int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}
int main()
{
    int n, factorial;
    printf("Enter the number which you want to know the factorial: \n");
    scanf("%d", &n);
    factorial = fact(n);
    printf("The factorial of %d is %d\n", n, factorial);
    return 0;
}