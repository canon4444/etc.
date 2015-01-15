#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM sizeof(int)

int pure_random()
{
int i;
int val = 0, tmp;

for( i = 0; i < NUM; ++i ){
tmp = rand() % 2;
val |= tmp;
val <<= 1;
}

return val;
}

int main()
{
srand(time(0));

int val = pure_random();

printf("%d\n", val);

return 0;
}
