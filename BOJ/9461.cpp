//category : dp

#include <stdio.h>

long long P[101];
int main(){

	int T;
	int i;
	P[1] = P[2] = P[3] = 1;
	P[4] = P[5] = 2;
	for (i = 6; i <= 100; i++) P[i] = P[i - 1] + P[i - 5];
	for (scanf("%d", &T); T--;){
		scanf("%d",&i);
		printf("%lld\n",P[i]);
	}
	return 0;
}

