//category : math

#include <stdio.h>
#define ll long long
int B, C;
ll A;

int main(){
	scanf("%lld%d%d",&A,&B,&C);
	ll ans = 1;
	
	while (B != 0){
		
		if (B & 1){
			ans *= A;
			ans %= C;
		}
		B>>=1;
		A *= A;
		A %= C;
	}
	printf("%lld",ans);
	return 0;
}
