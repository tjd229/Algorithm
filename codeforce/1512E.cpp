//math
#include <stdio.h>
using namespace std;
int p[501];
int cnt[501];
inline int min(int a, int b) { return a < b ? a : b; }
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int n, l, r, s; scanf("%d%d%d%d",&n,&l,&r,&s);
		int len = r - l + 1;
		for (int i = 1; i <= n; ++i) cnt[i] = 0;
		int mn = (len * (len + 1)) >> 1;
		int diff = n - len;
		int mx = mn + diff * len;
		if (mn > s || s > mx)
			printf("-1\n");
		else {
			int sum = 0;
			for (int i = 0; i < len; ++i) {
				sum += i + 1;
				p[i+l] = 1 + i;
			}
			mx = n; int i = r;
			
			while (sum < s && i>=l) {
				int diff = s - sum;
				sum -= p[i];
				p[i] = min(mx, p[i] + diff);
				sum += p[i];
				--mx; --i;
			}
			if (sum != s) {
				printf("-1\n");
			}
			else {
				for (int i = l; i <= r; ++i) ++cnt[p[i]];
				int ix = 1;
				for (i = 1; i < l; ++i) {
					while (cnt[ix] == 1) ++ix;
					p[i] = ix;
					++ix;
				}
				for (i = r + 1; i <= n; ++i) {
					while (cnt[ix] == 1) ++ix;
					p[i] = ix++;
				}
				for (i = 1; i <= n; ++i) printf("%d ",p[i]);
				puts("");
			}
		}
 
	}
 
	return 0;
}