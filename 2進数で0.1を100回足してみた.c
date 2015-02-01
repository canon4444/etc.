// http://ideone.com/ootc4J

#include <stdio.h>

int main(void) {
	int i, j;
	
	int cnt[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, tmp[12] = { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0 };
	
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
		
	for( i = 0; i < 12; ++i ){
		printf("%d ", cnt[i]);
		if( i == 3 ) printf(". ");
	}
	
	return 0;
}
