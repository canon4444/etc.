#include <stdio.h>
#include <math.h>

#define X 120

int num[X], prime[X];
int value, cnt;


int main()
{
    int i, j, rootX = sqrt(X)+1;

    cnt = 0;

        for( i = 0; i < X; ++i ){ //初期化
        if( i == 0 || i == 1 ) num[i] = -1;
        else num[i] = i;
    }

    for( i = 0; i < X; ++i ){ //初期化
        prime[i] = -1;
    }
    

    for( i = 0; i < rootX; ++i, ++cnt ){
        while( num[i] == -1 ) ++i; //篩い落とした値を飛ばす
        value = prime[cnt] = num[i]; //基数を素数表へ移す
        num[i] = -1;

        for( j = 0; value * j < X; ++j ){ //倍数を篩い落とす
            num[value * j] = -1;
        }
    }

    for( i = 0; i < X; ++i ){ //残りの値を素数表へ移す
        if( num[i] != -1 ) prime[cnt++] = num[i];
    }
    

    for( i = 0; i < cnt; ++i ){ //出力
        printf("%d", prime[i]);
        if( (i+1) % 5 == 0 ) printf("\n");
        else printf(" ");
    }

    return 0;
}
