//category : math

#include <stdio.h>
long long d[200000];
int main(){
	int i;
	long long n;
	long long A;
	long long max_sum = 0;
	long long out;
	long long res;
	scanf("%I64d%I64d",&n,&A);
	for (i = 0; i < n; i++){
		scanf("%I64d",d+i);
		max_sum += d[i];
	}
	for (i = 0; i < n; i++){
		res = A - (max_sum - d[i]);
		if (res <=0) res = 1;
		out = res-1;
		res = A - (n - 1);
		if (res <= d[i]) out += d[i] - res;
		printf("%I64d ",out);
	}
	return 0;
}