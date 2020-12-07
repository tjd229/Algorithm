//math
#include<stdio.h>
int a[200001];
long long diff[200002];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",a+i);
		long long s = 0,ans=-1;
		for (i = 2; i <= n; ++i) {
			diff[i] = 0;
			int d = a[i] - a[i - 1];
			if (d < 0) d = -d;
			s += d;
			diff[i] = d;
		}
		diff[n + 1] = 0;
		for (i = 1; i <= n; ++i) {
			int bk = a[i];
			if (i > 1) {
				s -= diff[i] + diff[i + 1];
				long long delta = 0;
				a[i] = a[i - 1];
				if (i > 1) {
					int d = a[i] - a[i - 1];
					if (d < 0) d = -d;
					delta += d;
				}
				if (i < n) {
					int d = a[i] - a[i + 1];
					if (d < 0) d = -d;
					delta += d;
				}
				s += delta;
				if (ans<0 ||ans > s) ans = s;
				//printf("%d:%lld\n",i,s);
				s -= delta; s += diff[i] + diff[i + 1];
				a[i] = bk;
			}
			if (i <n) {
				s -= diff[i] + diff[i + 1];
				long long delta = 0;
				a[i] = a[i + 1];
				if (i > 1) {
					int d = a[i] - a[i - 1];
					if (d < 0) d = -d;
					delta += d;
				}
				if (i < n) {
					int d = a[i] - a[i + 1];
					if (d < 0) d = -d;
					delta += d;
				}
				s += delta;
				if (ans<0 || ans > s) ans = s;
				//printf("%d:%lld\n", i, s);
				s -= delta; s += diff[i] + diff[i + 1];
				a[i] = bk;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
