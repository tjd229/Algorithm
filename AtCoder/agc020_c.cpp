//category : math

#include <stdio.h>
#include <bitset>
using namespace std;
int main(){
	int i;
	int N;
	int A;
	int S = 0;
	bitset<2000 * 2000> bs;
	bs[0] = 1;
 
	for (scanf("%d", &N); N--;){
		scanf("%d", &A);
		bs |= (bs << A);
		S += A;
	}
	
	S = (S >> 1) + (S & 1);
	while (!bs[S]) S++;
	printf("%d",S);
 
	return 0;
}
 
