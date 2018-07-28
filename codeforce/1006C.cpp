//line sweeping

#include <stdio.h>
#define ll long long
int d[200001];
int main(){
	int i;
	int n;
	ll sum1 = 0;
	ll sum3 = 0;
	ll ans = 0;
	for (scanf("%d", &n), i = 1; i <= n; i++) scanf("%d",d+i);
	int l = 1;
	int r = n;
	while (l <= r){
		if (sum1 == sum3){
			if (l != r){
				sum1 += d[l];
				sum3 += d[r];
			}
			++l; --r;
		}
		else if (sum1 < sum3){
			sum1 += d[l++];
		}
		else if (sum1 > sum3) sum3 += d[r--];
		if (sum1==sum3 && ans < sum1) ans = sum1;
		//printf("%lld,%lld\n",sum1,sum2);
	}
	printf("%I64d",ans);
	return 0;
}
