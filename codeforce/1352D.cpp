//line sweeping
#include <stdio.h>
int a[1001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",a+i);
		int mv = 0;
		int Alice = 0, Bob = 0;
		int l = 1, r = n;
		int last = 0;
		while (l<=r) {
			int sz = 0;
			while (l<=r &&sz <= last) 
				sz += a[l++];
			Alice += sz;
			++mv;
			last = sz;
			sz = 0;
			if (l > r) break;
			while (l <= r && sz <= last)
				sz += a[r--];
			Bob += sz;
			++mv;
			last = sz;
		}
		printf("%d %d %d\n",mv,Alice,Bob);
	}
 
}