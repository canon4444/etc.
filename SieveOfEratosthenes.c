#include <stdio.h>

int prime[1000];
int value, cnt;

void init()
{
    value = 2;
    cnt = 0;
}

int main()
{
    int i, flag;

    init();

    while( cnt < 1000 ){
        flag = 1;

        for( i = 0; i < cnt; ++i ){
            if( value % prime[i] == 0 ){
                flag = 0;
                break;
            }
        }
        if( flag ) prime[cnt++] = value;

        ++value;
    }

    for( i = 0; i < cnt; ++i ){
        printf("%d", prime[i]);
        if( (i+1) % 5 == 0 ) printf("\n");
        else printf(" ");
    }

    return 0;
}
