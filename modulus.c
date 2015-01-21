#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 1000
#define AMOUNT 100
#define N 15

int template[N];
int chrome[N][N + 1], nextchrome[N][N];

int main() {
    int i, j, tmp;

    srand(time(0));

/* template init する */
    for ( i = 0; i < N; ++i )
        template[i] = i + 1;
    for ( i = 0; i < N; ++i )
        printf( "template[%d] : %d\n", i, template[i] );
    printf ( "\n" );

/* chrome init する（templateをinitしてから） */
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j )
            chrome[i][j] = ((template[j]+i) % 15) + 1;
        chrome[i][N] = 0;
    }
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j <= N; ++j )
            printf( "chrome[%d][%d] : %d\n", i, j, chrome[i][j] );
        printf( "\n" );
    }


    int generate = 0;
    while ( generate++ < LIMIT ) {
        printf( "%d世代目\n", generate);

/* 適応度出す（絶対値） */
        int modulus;
        for ( i = 0; i < N; ++i )
            for ( j = 0; j < N; ++j ) {
                modulus = template[j] - chrome[i][j];
                if ( modulus < 0 )
                    modulus *= -1;
                chrome[i][N] += modulus;
            }


/* ソートする */
        int idx;
        for ( i = 0; i < N; ++i ) {
            for ( idx = j = i; j < N; ++j ) {
                if ( chrome[j][N] > chrome[idx][N] )
                    idx = j;
            }
            for ( j = 0; j <= N; ++j ) {
                tmp = chrome[i][j];
                chrome[i][j] = chrome[idx][j];
                chrome[idx][j] = tmp;
            }
        }

        
/* 局所解になっていたら終了する */
        int flag = 0;
        for ( i = 0; i < N; ++i )
            if ( chrome[0][N] == chrome[i][N] )
                ++flag;
        if ( flag > 7 )
            break;


/* 交叉する */
// nextchrome は毎世代 init する
        for ( i = 0; i < N; ++i )
            for ( j = 0; j < N; ++j )
                nextchrome[i][j] = 0;
        
        int m, n;
/* 偶数の cell を埋める */
        for ( i = 1; i < N; i += 2 ) {
            for ( j = 0; j < N; j += 2 ) {
                nextchrome[i-1][j] = chrome[i-1][j];
                nextchrome[i][j] = chrome[i][j];
            }

/* 重複している値を 0 にする */
            for ( j = 0, m = 0, n = 0; j < N; j += 2, m = 0, n = 0 ) {
                while ( nextchrome[i-1][j] != chrome[i][m] ) ++m;
                if ( nextchrome[i-1][j] == chrome[i][m] )
                    chrome[i][m] = 0;
                while ( nextchrome[i][j] != chrome[i-1][n] ) ++n;
                if ( nextchrome[i][j] == chrome[i-1][n] )
                    chrome[i-1][n] = 0;
            }
           

/* 奇数の cell を埋める */
            for ( j = 1, m = 0, n = 0; j < N; j += 2 ) {
                while ( chrome[i][m] == 0 ) ++m;
                nextchrome[i-1][j] = chrome[i][m];
                while ( chrome[i-1][n] == 0 ) ++n;
                nextchrome[i][j] = chrome[i-1][n];
            }
        }

/* 世代交代 */
        for ( i = 0; i < N; ++i ) {
            for ( j = 0; j < N; ++j )
                chrome[i][j] = nextchrome[i][j];
            chrome[i][N] = 0;
        }
        


/* 突然変異する */
        for ( i = 0; i < N; ++i ) {
            if ( rand() % 100 <= 25 ) {
                m = rand() % 15;
                n = rand() % 15;
                tmp = chrome[i][m];
                chrome[i][m] = chrome[i][n];
                chrome[i][n] = tmp;
            }
        }

        for ( i = 0; i < N; ++i ) {
            for ( j = 0; j < N; ++j )
                printf("%2d ", chrome[i][j]);
            printf(": %2d\n", chrome[i][N]);
        }
    }

/* 解を出力する */
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j )
            printf( "%2d ", chrome[i][j] );
        printf( ": %2d ", chrome[i][N] );
        printf( "\n" );
    }
    
    return 0;
}
