//implementation
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
int a[100002];
int mex(int n) {
	for (int i = 1; i <= n; ++i) {
		if (i-1 != a[i]) return i - 1;
	}
	return n;
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n, k;
		set<int> S;
		for (scanf("%d%d", &n, &k), i = 1; i <= n; ++i) scanf("%d", a + i),S.insert(a[i]);
		sort(a + 1, a + 1 + n);
		int mx = mex(n);
		if (mx == n) {
			printf("%d\n",n+k);
			continue;
		}
		if (k == 0) {
			printf("%d\n",S.size());
			continue;
		}
		--k;
		int s = mx + a[n];
		int e = (s >> 1) + (s & 1);
		if (S.find(e) == S.end()) {
			S.insert(e);
			a[++n] = e;
			sort(a + 1, a + 1 + n);
		}
		if (mex(n) == n) printf("%d\n",S.size()+k);
		else printf("%d\n",S.size());
		
		
	}
 
	return 0;
}