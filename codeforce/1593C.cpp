//bs, greedy
#include <stdio.h>
#include <algorithm>
using namespace std; 
int n, k;
int x[400001];
bool sim(int m) {
	int cat = 0;
	for (int i = m; i <= k; ++i) {
		if (cat >= x[i]) return 0;
		cat += n - x[i];
	}
	return 1;
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i;
		for (scanf("%d%d", &n, &k), i = 1; i <= k; ++i) scanf("%d",x+i);
		sort(x + 1, x + 1 + k);
		int l = 1, r = k;
		int ans = 0;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (sim(m)) {
				if (ans < k-m+1) ans =1+k- m;
				r = m - 1;
			}
			else l = m + 1;
		}
		printf("%d\n",ans);
	}
 
	return 0;
}