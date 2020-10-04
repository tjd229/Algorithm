//dp, line sweeping
#include <stdio.h>
#include <algorithm>
using namespace std;
int x[200001];
int d[200001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n,k;
		for (scanf("%d%d",&n,&k), i = 1; i <= n; ++i) scanf("%d",x+i);
		for (i = 1; i <= n; ++i) {
			int _; scanf("%d",&_);
		}
		sort(x + 1, x + 1 + n);
		int l = 1, r = 1;
		int mx = 0;
		int save = 0;
		for (; r <= n; ++r) {
			while (l < r && x[r] - x[l] > k) {
				if (mx < d[l]) mx = d[l];
				++l;
			}			
			d[r] = r - l + 1;
			int cnt = d[r] + mx;
			if (save < cnt) save = cnt;
		}
		
		printf("%d\n",save);
	}
	return 0;
}
