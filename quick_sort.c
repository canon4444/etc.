#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 100

int src[NUM];

//中央値を選択
void middle_value(int min, int mid, int max)
{
    int tmp;
    
    while( 1 ){
        if( src[min] <= src[mid] && src[mid] <= src[max] ) break;
        if( rand() % 2 ) tmp = src[min], src[min] = src[mid], src[mid] = tmp;
        else tmp = src[max], src[max] = src[mid], src[mid] = tmp;
    }
}

void quick_sort(int min, int max)
{
    int i, j, k;
    int mid = (max - min) / 2, tmp;

    middle_value(min, mid, max);
    /*
    while( 1 ){
        for( max = 0; max < mid; ++max )
            if( src[mid] < src[max] ) break;
        for( min = NUM - 1; mid < min; --min )
            if( src[min] < src[mid] ) break;
        if( mid < max && min < mid ) break;
        tmp = src[max];
        src[max] = src[min];
        src[min] = tmp;
    }
    */
}

int main()
{
    int i;
    
    srand(time(0));
    
    for( i = 0; i < NUM; ++i ) src[i] = rand() % NUM;
    
    quick_sort(0, NUM-1);
    
    //for( i = 0; i < NUM; ++i ) printf("%d ", src[i]);
    
    return 0;
}
