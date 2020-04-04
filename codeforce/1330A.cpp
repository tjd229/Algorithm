//implementation
#include <stdio.h>
int main() {
	int i,t;
	for (scanf("%d", &t); t--;) {
		int cnt[250] = { 0 };
		int v,n,x;
		for (scanf("%d%d", &n, &x), i = 1; i <= n; ++i) {
			int a; scanf("%d",&a);
			cnt[a] = 1;
		}
		for (i = 1; i < 250 && x; ++i) {
			if (cnt[i] == 0) {
				--x;
				cnt[i] = 1;
			}
		}
		v = i - 1;
		for (i = v; i < 250 && cnt[i]; ++i) {
			v = i;
		}
		printf("%d\n",v);
	}
 
	return 0;
}