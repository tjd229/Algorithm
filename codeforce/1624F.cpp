//bs, math
#include <stdio.h>
int cmd(int c) {
	printf("+ %d\n", c); fflush(stdout);
	int d; scanf("%d",&d);
	return d;
}
int main() {
	int i, n; scanf("%d",&n);
	int cum = 0;
	int d = 0;
	int l = 1, r = n - 1;
	while (l <= r) {
		if (r == l) break;
		int m = (l + r) >> 1;
		if (l == m) {
			int pred = cum + m;
			int rem = n - pred % n - 1;
			if (rem == 0) {//cum+l == n-1
				int div = cmd(1); cum += 1;
				if (d == div) l = r;
				else;
			}
			else {
				int div = cmd(rem); cum += rem;
				if (d == div);
				else l = r;
			}
			break;
		}
		if ((cum + l) / n == (cum + m) / n) {
			int pred = cum + m;
			int rem = n - pred % n-1;
			int div = cmd(rem); cum += rem;
			if (div == d) r = m;
			else {
				l = 1 + m;
				d = div;
			}
		}
		else {
			int pred = cum + m;
			int rem = n - pred % n - 1;
			d = (cum+l) / n;
			int div = cmd(rem); cum += rem;
			if (div == d + 2) {
				l = 1 + m;
				d = div;
			}
			else r = m;
		}
 
 
	}
	printf("! %d", cum + l); fflush(stdout);
 
	return 0;
}