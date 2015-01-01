#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RATE 50

int Good_night(int number);

int main(void)
{
    int sheep;

    srand(time(0));

    for( sheep = 1; Good_night(sheep); ++sheep )
        printf("The number of sheep is %d...\n", sheep);

    printf("Good night, World......\n");

    while( --sheep )
        printf("zzZZ...\n");

    printf("Hello, World!\n");

    return 0;
}

int Good_night(int number)
{
    return (RATE < rand() % 100 + number);
}
