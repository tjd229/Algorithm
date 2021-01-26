//greedy
#include <stdio.h>
 
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		int cnt1 = 0, cnt2 = 0;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			int a; scanf("%d",&a);
			if (a == 1) ++cnt1;
			else ++cnt2;
		}
		if (cnt1 > 1 && (cnt2 & 1)) {
			cnt1 -= 2;
			cnt2 = 0;
		}
		if (cnt2 & 1)
			printf("NO\n");
		else printf("%s\n",cnt1&1? "NO":"YES");
	}
 
	return 0;
}