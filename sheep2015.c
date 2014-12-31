#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Good_night(int number);

int main(void)
{
    int sheep;

    for( sheep = 0; Good_night(sheep); ++sheep )
        printf("The number of sheep is %d...\n", sheep);

    printf("Good night, World......\n");

    while( --sheep )
        printf("zzZZ...\n");

    printf("Hello, World!\n");

    return 0;
}

int Good_night(int number)
{
    return (number % 2) & (rand() % 2);
}
