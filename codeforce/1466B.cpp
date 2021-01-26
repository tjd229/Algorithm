//greedy
#include <stdio.h>
#include <map>
using namespace std; 
int x[100001];
int cnt[200011];
 
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",x+i);
		int nn = n + n;
		for (i = 0; i <= nn+1; ++i) cnt[i] = 0;
		for (i = 1; i <= n; ++i) ++cnt[x[i]];
		for (i = 1; i <= n; ++i) {
			if (cnt[x[i]] > 1) {
				--cnt[x[i]];
				++cnt[x[i] + 1];
			}
		}
		int ans = 0;
		for (i = 0; i <= nn + 1; ++i) ans += (cnt[i] > 0);
		printf("%d\n",ans);
	}
	return 0;
}