// http://ideone.com/ootc4J
// 10進数の0.1を2進数(0.00011)で100回足す

#include <stdio.h>

double pow(int n) {
	int i;
	
	double val = 1.0;
	
	if( 0 < n ){
		for( i = 0; i < n; ++i ) val *= 2.0;
	} else if( n < 0 ){
		for( i = 0; n < i; --i ) val /= 2.0;
	}
	
	return val;
}

int main(void) {
	int i, j;
	
	int cnt[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	    tmp[12] = { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0 };
	
	for( i = 0; i < 100; ++i ){
		for( j = 11; -1 < j; --j ){
			cnt[j] += tmp[j];
			switch( cnt[j] ){
			  case 0: break;
				case 1: break;
				case 2: cnt[j-1] += 1, cnt[j] = 0; break;
				case 3: cnt[j-1] += 1, cnt[j] = 1; break;
				default: printf("default: cnt[%d]\n", j); break;
			}
		}
	}
	
	printf("2進数:\n\t");
	for( i = 0; i < 12; ++i ){
		printf("%d ", cnt[i]);
		if( i == 3 ) printf(". ");
	}
	printf("\n");
	
	double sum = 0;
	printf("10進数:\n\t");
	for( i = 0; i < 12; ++i ){
		sum += cnt[i] * pow(3-i);
	}
	printf("%f\n", sum);
	
	return 0;
}
