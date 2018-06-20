//category : math

#include <stdio.h>
#define ll long long
int main(){
	ll n, m;
	int a, b;
	scanf("%I64d%I64d%d%d",&n,&m,&a,&b);
	if (n%m == 0) printf("0");
	else{
		ll costa = a*(m-n%m);
		ll costb = b*(n%m);
		printf("%I64d",costa<costb? costa:costb);
	}

	return 0;
}
