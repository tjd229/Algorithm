//greedy

#include <stdio.h>
#define ll long long
int b[1000001],a[1000001];
int post[1000001];
int main(){
	int i;
	int n, m, k;
	int mn = 0;
	int l = 0;
	for (scanf("%d%d%d", &n, &m, &k),i=0; m--;){
		int s;
		scanf("%d",&s);
		b[s] = 1;
		if (s > 0 && b[s - 1]) ++i;
		else
			i = 1;
		
		if (mn < i) mn = i;
	}
	for (i = 0; i <= n; i++){
		post[i] = l;
		if (!b[i]) l = i;
	}
	for (i = 1; i <= k; i++) scanf("%d",a+i);
	ll ans = -1;
	for (l = mn + 1; l <= k; ++l){
		i = 0;
		ll tot = 0;
		while (i <= n){
			if (b[post[i]]) break;
			tot += a[l];
			i = post[i]+l+1;
			//printf("i:%d\n",i);
		}
		if (i > n){
			if (ans == -1 || ans > tot) ans = tot;
		}
	}
	printf("%I64d",ans);

	return 0;
}
