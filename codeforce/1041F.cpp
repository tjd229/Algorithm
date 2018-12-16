//math

#include <stdio.h>
#include <unordered_map>
using namespace std;
int a[100000],b[100000];

inline int max(int a, int b) { return a < b ? b : a; }
int main() {
	int i;
	int n, m, _;
	int ans = 0;
	for (scanf("%d%d", &n, &_), i = 0; i < n; ++i) scanf("%d",a+i);
	for (scanf("%d%d", &m, &_), i = 0; i < m; ++i) scanf("%d", b + i);
	int d = 1;
	int mx = max( b[m - 1], a[n - 1]);
	while (d <= mx) {
		unordered_map<int, int> cnt;
		int mod = d << 1;
		for (i = 0; i < n; ++i) {
			int v = a[i] & (mod-1);
			ans = max(ans, ++cnt[v]);
		}
		for (i = 0; i < m; ++i) {
			int v = (b[i]+d) & (mod - 1);
			ans = max(ans, ++cnt[v]);
		}
		d = mod;
	}
	if (ans <= 1) {
		unordered_map<int, int> cnt;
		int mod = 1e9 + 7;
		for (i = 0; i < n; ++i) {
			int v = a[i] % mod;
			ans = max(ans, ++cnt[v]);
		}
		for (i = 0; i < m; ++i) {
			int v = b[i] % mod;
			ans = max(ans, ++cnt[v]);
		}
		
	}
	printf("%d", ans);

	return 0;
}
