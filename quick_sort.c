#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 100

int src[NUM];

void quick_sort()
{
    int i, j, k;
    int mid;

    if()



}

int main()
{
    int i;
    
    srand(time(0));
    
    for( i = 0; i < NUM; ++i ) src[i] = rand() % NUM;
    
    quick_sort();
    
    for( i = 0; i < NUM; ++i ){ printf("%d", src[i]); if( i & !(i%6) ) printf("\n"); }
    
    return 0;
}
