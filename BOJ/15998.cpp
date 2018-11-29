//math
#include <stdio.h>
#define ll long long
ll a[300001], b[300001];
ll gcd(ll a, ll b){
	if (a > b) a ^= b ^= a ^= b;
	if (a == 0) return b;
	return gcd(b%a, a);
}
int main(){
	int i;
	int N;
	ll M = 0;
	bool wrong = false;
	for (scanf("%d", &N), i = 1; i <= N; ++i){
		scanf("%lld%lld",a+i,b+i);
		if (a[i] < 0 && b[i - 1] < -a[i]){
			ll aM = b[i] - a[i] - b[i - 1];
			if (M == 0) M = aM;
			else M = gcd(M, aM);
		}
		wrong |= (a[i] > 0 && a[i] != b[i]-b[i-1]);
		wrong |= (a[i] < 0 && a[i] != b[i] - b[i-1] && b[i - 1] >= -a[i]);
	}
	if (wrong) printf("-1");
	else{
		for (i = 1; i <= N &&!wrong; ++i){
			if (a[i] < 0 & b[i - 1] < -a[i]){
				wrong |= (M <= b[i]);
			}
		}
		if (M == 0) ++M;
		printf("%lld",wrong? -1:M);
	}
	return 0;
}
