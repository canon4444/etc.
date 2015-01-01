#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 100

int src[NUM];

void quick_sort()
{
    int i, j, k;
    int min, mid, max, tmp;

    //中央値を選択
    min = 0, mid = NUM / 2 - 1, max = NUM - 1;
    if ( src[mid] < src[min] ){
        tmp = min;
        min = mid;
        mid = tmp;
    }
    if ( src[max] < src[min] ) mid = min;
    else if ( src[max] < src[mid] ) mid = max;
    tmp = src[NUM / 2 - 1];
    src[NUM / 2 - 1] = src[mid];
    src[mid] = tmp;

    for( max = 0; max < mid; ++max )



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
