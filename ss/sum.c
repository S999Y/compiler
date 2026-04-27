#include <stdio.h>

int sumRec(int sum, int n)
{
    if (n <= 0)
    {
        return 0;
    }

    return sum = sum + n + sumRec(sum, n - 1);
}

int main()
{
    int n = 5;
    int sum = 0;
    sum = sumRec(sum, n);

    printf("%d\n", sum);

    return 0;
}