//greedy, math
#include <stdio.h>
#include <queue>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int mod = 1e9 + 7;
long long c[1001][1001];
int a[1001];
int cnt[1001];
int main() {
	int i,j,t;
	for (i = 0; i <= 1000; ++i) {
		c[i][0] = 1;
		for (j = 1; j <= i; ++j) {
			c[i][j] = (c[i - 1][j-1] + c[i-1][j]) % mod;
		}
	}
	for (scanf("%d", &t); t--;) {
		int n, k;
		for (scanf("%d%d", &n, &k), i = 1; i <= n; ++i) scanf("%d",a+i),cnt[i]=0;
		for (i = 1; i <= n; ++i) ++cnt[a[i]];
		int ans = 1;
		for (i = n; i > 0 && k; --i) {
			if (cnt[i] > k) {
				ans = c[cnt[i]][k];
				break;
			}
			k -= cnt[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}