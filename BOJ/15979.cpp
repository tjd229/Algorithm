//geometry, math
#include <stdio.h>
int gcd(int a,int b){
	if (a == 0) return b;
	return gcd(b%a, a);
}
int main(){
	int M, N;
	scanf("%d%d",&M,&N);
	if (M == 0 && N == 0) printf("0");
	else if (N == 1 || N == -1) printf("1");
	else if (M == 1 || M == -1) printf("1");
	else{
		if (M == N) printf("2");
		else{
			if (M < 0) M = -M;
			if (N < 0) N = -N;
			if (M < N) M ^= N ^= M ^= N;
			if (gcd(M, N) == 1) printf("1");
			else printf("2");
		}
	}

	return 0;
}
