#include <stdio.h>

int sumRec(int sum, int n)
{
    if (n <= 0)
    {
        return 0;
    }

    return sum = sum + n + sumRec(sum, n - 1);
}

int factorial(int x){

    if(x == 0){
        return 1;
    }

    return x * factorial(x - 1);
}

int main()
{
    int n = 5;
    int fact = factorial(n);

    printf("Factorial of %d is %d\n", n, fact);
    
    return 0;
}