#include <stdio.h>
#include <math.h>

#define X 7
#define N 10

int mod_pow(int x, int n)
{
    if( n == 1 ) return x;

    int value = mod_pow(x * x, n/2);

    if( n % 2 ) return value * x;
    else return value;
}

int main()
{
    printf("func: %d\n", mod_pow(X, N));
    printf("Ans : %g\n", pow(X, N));

    return 0;
}
