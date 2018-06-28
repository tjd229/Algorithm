//category : greedy

#include <stdio.h>
int a[100001];
int sum[200001];
int main(){
	int n;
	int s, f;
	int hour = 1;
	int maxv = 0;
	int ans = 0;
	int i;
	for (scanf("%d", &n), i = 1; i <= n; i++){
		scanf("%d",a+i);
		sum[i] = sum[i - 1] + a[i];
	}
	for (scanf("%d%d",&s,&f),i = 1; i <= n; i++) sum[n + i] = sum[n + i - 1] + a[i];
	int r = f - s;
	for (i = n; i > 0; i--,hour++){
		int v = sum[i + r] - sum[i];
		if (v > maxv){
			ans = hour + s - 1;
			if (ans > n) ans -= n;
			maxv=v;
		}
		else if (v == maxv){
			int t = hour + s - 1;
			if (t > n) t -= n;
			if (ans > t) ans = t;
		}
	}
	printf("%d",ans);
	return 0;
}
