//greedy
#include <stdio.h>
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int n, k; scanf("%d%d",&n,&k);
		int c = k-1;
		int last = n - c;
		bool flag = 1;
		if (k == 1) {
			printf("YES\n%d\n",n);
			continue;
		}
		if (last <= 0 ) flag = 0;
		if ((last & 1) == 0) {
			c += c;
			last = n - c;
			if ((last & 1) == 1) flag = 0;
			if (last <= 0)flag = 0;
		}
		if (flag) {
			printf("YES\n");
			for (int i = 1; i < k; ++i) printf("%d ",c/(k-1));
			printf("%d\n",last);
		}
		else printf("NO\n");
	}
	return 0;
}