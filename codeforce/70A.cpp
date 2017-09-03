//category : math

#include <stdio.h>
#define MOD 1000003
long long pow(long long a, int n){
	long long res = 1;
	while (n != 0){
		if (n & 1){
			res *= a;
			if (res >= MOD) res %= MOD;
		}
		a *= a;
		if (a >= MOD) a %= MOD;
		n >>= 1;
	}
	return res;
}

int main(){
	int n;
	scanf("%d",&n);
	if (n == 0){
		printf("1");
		return 0;
	}
	printf("%I64d",pow(3,n-1));
}