//category : math

#include <stdio.h>
int gcd(int a, int b){
	if (b == 0) return a;
	return gcd(b, a%b);
}
int main(){
	int T;
	int A, B;
	int base;
	for (scanf("%d", &T); T--;){
		scanf("%d%d",&A,&B);
		base = A < B ? gcd(B, A) : gcd(A, B);
		printf("%d\n", base*(A / base)*(B / base));
	}

	return 0;
}
