//sqrt Decomp., bs
#include <stdio.h>
const int seg = 32;//num_g=6000
int n,g[7000];
int ask(int l, int r) {
	printf("? %d %d\n", l, r); fflush(stdout);
	int sum; scanf("%d", &sum);
	return sum;
}
int find(int k) {
	int cum = 0;
	for (int i = 0;; ++i) {
		if (cum + g[i] >= k) {
			k -= cum;
			int l = seg * i, r = l + seg-1;
			if (r > n - 1) r = n - 1;
			++l, ++r;
			while (l <= r) {
				if (l == r) return l;
				int m = (l + r) >> 1;
				int len = m - l + 1;
				int sum = ask(l, m);
				int cnt = len - sum;
				if (k <= cnt) r = m;
				else {
					k -= cnt;
					l = m + 1;
				}
			}
		}
		cum += g[i];
	}
	return -1;
}
int main() {
	int i,t, k; scanf("%d%d%d", &n, &t, &k);

	int s = 0, e = seg;
	while (s < n) {
		int l = s, r = e - 1;
		if (r > n-1) r = n-1;
		int len = r - l + 1;
		g[s / seg] = len-ask(l + 1, r + 1);
		s = r + 1; e = s + seg;
	}
	int pos = find(k);
	printf("! %d\n", pos); fflush(stdout);
	--pos; --g[pos / seg];
	while (--t) {
		scanf("%d",&k);
		pos = find(k);
		printf("! %d\n", pos); fflush(stdout);
		--pos;  --g[pos / seg];
	}
	

	return 0;
}