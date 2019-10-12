//greedy
#include <stdio.h>
#include <algorithm>
using namespace std;
int x[100001];
int main() {
	int i, q;
	for (scanf("%d", &q); q--;) {
		int n, r;
		for (scanf("%d%d", &n, &r), i = 1; i <= n; ++i)
			scanf("%d",x+i);
		sort(x+1,x+1+n);
		int s = 1, e = n;
		int trap = 0;
		int cnt = 0;
		while (s <= e) {
			++cnt;
			trap += r;
			int tgt = x[e];
			while (tgt == x[e]) --e;
			while (s<=n&&x[s] <= trap) ++s;
		}
		printf("%d\n",cnt);
	}
	return 0;
}