// 途中

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

double Jaccard(vector<int>::iterator v, vector<int>::iterator q)
{
    int cap = 0, cup = 0;
    
    for( auto i, j : v, q ){
        if( *i == *j ) ++cap;
        else ++cup;
    }
    
    return cap / cup;
}


int main() {
	srand(time(0));

	return 0;
}
