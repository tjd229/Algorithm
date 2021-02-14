//math
#include <stdio.h>
 
int main() {
	int t; 
	for (scanf("%d", &t); t--;) {
		int i, a, b; scanf("%d%d",&a,&b);
		if (a < b) {
			printf("1\n");
		}
		else if (a == b) {
			printf("2\n");
		}
		else {
			int ans = 1e9;
			int base = 0;
			int last = ans;
			while (1) {
				if (b == 1) {
					++b; ++base;
					continue;
				}
				int cnt = base;
				int _a = a;
				while (_a) {
					_a /= b;
					++cnt;
				}
				if (ans > cnt) ans = cnt;
				if (last < cnt) break;
				last = cnt;				
				++b; ++base;
			}
			printf("%d\n",ans);
		}
	}
 
	return 0;
}