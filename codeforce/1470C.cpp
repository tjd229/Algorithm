//bs, sqrt Decomp.
#include <stdio.h>
 
int n, k;
int qry(int q) {
	if (q > n) q -= n;
	else if (q < 1) q += n;
	printf("? %d\n", q); fflush(stdout);
	int num; scanf("%d",&num);
	return num;
}
int main() {
	int i; scanf("%d%d", &n, &k);
	if (n <= 1000) {
		qry(1);
		int st = 0;
		for (i = 2; i <= n && st == 0; ++i) {
			int num=qry(i);
			if (num > k) {
				printf("! %d", i-1);
				fflush(stdout);
				return 0;
			}
			else if (num != k) st = i;
		}
		while (1) {
			++st;
			if (st > n) st = 1;
			int num = qry(st);
			if (num == k) {
				printf("! %d",st);
				fflush(stdout);
				return 0;
			}
		}
	}
	else {
		int step = 1000;
		int base = 1;
		int len = 0;
		qry(1);
		int st = 0,num;
		int impostor = 0;
		while (st == 0) {
			int ix = base;
			while (st==0 &&ix <= n) {
				num = qry(ix);
				if (num != k) 
					st = ix;				
				ix += step;
				++len;
			}
			if (++base > n) base = 1;
		}
		if (num < k) {
			int l = st, r = l + len;
			while (l <= r) {
				int m = (l + r) >> 1;
				num = qry(m);
				if (num == k) {
					impostor = m;
					break;
				}
				else if (num > k) r = m - 1;
				else l = m + 1;
			}
		}
		else {
			int r = st, l = r - len;
			while (l <= r) {
				int m = (l + r) / 2;
				num = qry(m);
				if (num == k) {
					impostor = m;
					break;
				}
				else if (num > k) r = m - 1;
				else l = m + 1;
			}
		}
		if (impostor > n) impostor -= n;
		else if (impostor < 1) impostor += n;
		printf("! %d", impostor);
		fflush(stdout);
	}
	return 0;
}