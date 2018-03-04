//category : greedy

#include <stdio.h>
#define ll long long
ll a[100001];
int main(){
	int i;
	ll N;
	int K;
	ll max = 0;
	int ans = 0;
	
	for (i = 1, scanf("%I64d%d", &N, &K); i <= K; i++) scanf("%I64d",a+i);
	for (i = 1; i <= K; i++){
		ll cnt = N / a[i];
		if (max < cnt*a[i]){
			max = cnt*a[i];
			ans = i;
		}
	}
	if (ans == 0)
		printf("1 0");
	else
		printf("%d %I64d",ans,N/a[ans]);


}
