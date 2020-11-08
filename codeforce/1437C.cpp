//dp
#include <stdio.h>
#include <algorithm>
using namespace std;
const int inf = 1e9;
int d[201][401];
int t[201];
int main() {
	int q;
	for (scanf("%d", &q); q--;) {
		int i, j, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",t+i);
		sort(t + 1, t + 1 + n);
		int nn = n + n;
		for (i = 1; i <= n; ++i) for (j = 0; j <= nn; ++j) d[i][j] = inf;
		
		for (i = 1; i <= n; ++i) {
			int mn = d[i-1][i-1];
			for (j = i; j <= nn; ++j) {
				int unp = j - t[i];
				if (unp < 0) unp = -unp;
				d[i][j] = unp + mn;
				if (mn > d[i - 1][j]) mn = d[i-1][j];
			}
		}
		int ans = inf;
		for (i = n; i <= nn; ++i) if (ans > d[n][i]) ans = d[n][i];
		printf("%d\n",ans);
	}

	return 0;
}