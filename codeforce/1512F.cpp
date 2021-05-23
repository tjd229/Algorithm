//greedy
#include <stdio.h>
#define ll long long
int a[200001];
int b[200001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n,c;
		ll have = 0;
		ll ans = -1;
		ll ckpt = 0;
		for (scanf("%d%d",&n,&c),i = 1; i <= n; ++i) scanf("%d",a+i);
		for (i = 1; i < n; ++i) scanf("%d",b+i);
		for (i = 1; i <n; ++i) {
			if (c >= have) {
				int need = c - have;
				ll day = need / a[i] + ((need % a[i]) > 0) + ckpt;
				if (ans<0 || ans>day) ans = day;
			}
			else {
				if (ans<0 || ans>ckpt) ans = ckpt;
			}
			
			if (have < b[i]) {
				int need = b[i] - have;
				ll day = need / a[i] + ((need % a[i]) > 0);
				ckpt += day;
				have += (ll)day * a[i];
			}
			have -= b[i]; ++ckpt;
		}
		if (c >= have) {
			int need = c - have;
			ll day = need / a[n] + ((need % a[n]) > 0) + ckpt;
			if (ans<0 || ans>day) ans = day;
		}
		else {
			if (ans<0 || ans>ckpt) ans = ckpt;
		}
		printf("%I64d\n",ans);
	}
 
	return 0;
}