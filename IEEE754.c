//IEEE754形式（手打ち）をdouble型に変換

#include <stdio.h>
#include <math.h>

int main()
{
    int i, j;

    //S:符号部 E:指数部 f:仮数部
    int S = 1, E[11] = { 0,1,1,1,1,1,1,1,1,1 }, f[52] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };

    double v;
    int s, e;
    double m;


    if( S ) s = 1;
    else s = -1;

    m = 1;
    for( i = 0; i < 52; ++i ){
        m += f[i] * pow(2, i-52);
    }

    e = -1023;
    for( j = 0; j < 11; ++j ){
        e += E[j] * pow(2, j);
    }

    if( e == 1023 ){
        if( m != 0 ) printf("NaN\n");
        else if( s ) printf("+inf\n");
        else printf("-inf\n");
    }


    v = s * m * pow(2, e);
    printf("v = s * m * 2^e\n  = %d * %g * 2^(%d)\n  = %g\n", s, m, e, v);

    return 0;
}
