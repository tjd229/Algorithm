//category : math
#include <stdio.h>

int main(){
	long long n, k;
	scanf("%I64d%I64d",&n,&k);
	if (k == 0 || n == k){
		printf("0 0");
		//return 0;
	}
	else if (k * 3 < n){
		printf("1 %I64d",k<<1);
	}

	else{
		printf("1 %I64d",n-k);
	}
	return 0;
}